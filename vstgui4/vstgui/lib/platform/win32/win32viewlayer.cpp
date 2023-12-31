// This file is part of VSTGUI. It is subject to the license terms
// in the LICENSE file found in the top-level directory of this
// distribution and at http://github.com/steinbergmedia/vstgui/LICENSE

#include "win32viewlayer.h"
#include "win32directcomposition.h"
#include "win32factory.h"
#include "direct2d/d2dgraphicscontext.h"
#include "direct2d/d2d.h"

//------------------------------------------------------------------------
namespace VSTGUI {

//------------------------------------------------------------------------
Win32ViewLayer::Win32ViewLayer (const DirectComposition::VisualPtr& visual,
								IPlatformViewLayerDelegate* inDelegate,
								DestroyCallback&& destroyCallback)
: visual (visual), delegate (inDelegate), destroyCallback (std::move (destroyCallback))
{
}

//------------------------------------------------------------------------
Win32ViewLayer::~Win32ViewLayer () noexcept
{
	getPlatformFactory ().asWin32Factory ()->getDirectCompositionFactory ()->removeVisual (visual);
	destroyCallback (this);
}

//------------------------------------------------------------------------
void Win32ViewLayer::fire ()
{
	if (drawInvalidRects ())
	{
		if (!visual->commit ())
			invalidRect (viewSize);
	}
	timer = nullptr;
}

//------------------------------------------------------------------------
bool Win32ViewLayer::drawInvalidRects ()
{
	if (invalidRectList.empty ())
		return false;
	for (const auto& r : invalidRectList)
	{
		visual->update (r, [&] (auto deviceContext, auto updateRect, auto offsetX, auto offsetY) {
			COM::Ptr<ID2D1Device> device;
			deviceContext->GetDevice (device.adoptPtr ());

			CGraphicsTransform tm;
			tm.translate (offsetX - updateRect.left, offsetY - updateRect.top);

			const auto& graphicsDeviceFactory = static_cast<const D2DGraphicsDeviceFactory&> (
				getPlatformFactory ().asWin32Factory ()->getGraphicsDeviceFactory ());
			auto graphicsDevice = graphicsDeviceFactory.find (device.get ());
			auto drawDevice = std::make_shared<D2DGraphicsDeviceContext> (
				*static_cast<D2DGraphicsDevice*> (graphicsDevice.get ()), deviceContext, tm);

			drawDevice->setClipRect (updateRect);
			drawDevice->clearRect (updateRect);
			delegate->drawViewLayerRects (drawDevice, 1, {1, updateRect});
		});
	}
	lastDrawTime = getPlatformFactory ().getTicks ();
	invalidRectList.clear ();
	return true;
}

//------------------------------------------------------------------------
void Win32ViewLayer::invalidRect (const CRect& size)
{
	auto r = size;
	r.normalize ();
	r.makeIntegral ();
	r.bound (viewSize);
	invalidRectList.add (r);
	if (!timer)
	{
		auto ticks = getPlatformFactory ().getTicks () - lastDrawTime;
		if (ticks > 15)
			ticks = 0;
		timer = makeOwned<WinTimer> (this);
		timer->start (static_cast<uint32_t> (ticks));
	}
}

//------------------------------------------------------------------------
void Win32ViewLayer::setSize (const CRect& size)
{
	invalidRectList.clear ();

	auto r = size;
	r.normalize ();
	r.makeIntegral ();
	visual->setPosition (static_cast<uint32_t> (r.left), static_cast<uint32_t> (size.top));
	visual->resize (static_cast<uint32_t> (r.getWidth ()), static_cast<uint32_t> (r.getHeight ()));
	viewSize = r;
	viewSize.originize ();
	invalidRect (viewSize);
}

//------------------------------------------------------------------------
void Win32ViewLayer::setZIndex (uint32_t zIndex)
{
	visual->setZIndex (zIndex);
}

//------------------------------------------------------------------------
void Win32ViewLayer::setAlpha (float alpha)
{
	visual->setOpacity (alpha);
	visual->commit ();
}

//------------------------------------------------------------------------
void Win32ViewLayer::onScaleFactorChanged (double newScaleFactor) {}

//------------------------------------------------------------------------
const DirectComposition::VisualPtr& Win32ViewLayer::getVisual () const
{
	return visual;
}

//------------------------------------------------------------------------
} // VSTGUI
