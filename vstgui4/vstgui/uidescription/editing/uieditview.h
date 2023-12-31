// This file is part of VSTGUI. It is subject to the license terms
// in the LICENSE file found in the top-level directory of this
// distribution and at http://github.com/steinbergmedia/vstgui/LICENSE

#pragma once

#include "../../lib/cviewcontainer.h"

#if VSTGUI_LIVE_EDITING

#include "../../lib/cbitmap.h"
#include "../../lib/ccolor.h"
#include "../../lib/dragging.h"

namespace VSTGUI {
class UIUndoManager;
class UISelection;
class UIDescription;
class IUIDescription;
class UICrossLines;
class ViewSizeChangeOperation;
class IGridProcessor;
namespace UIEditViewInternal {
	class UIHighlightView;
} // UIEditViewInternal

//----------------------------------------------------------------------------------------------------
class UIEditView : public CViewContainer, public IDropTarget
{
public:
	UIEditView (const CRect& size, UIDescription* uidescription);
	~UIEditView () override;

	void enableEditing (bool state);
	void enableAutosizing (bool state);
	void setScale (double scale);

	void setEditView (CView* view);
	CView* getEditView () const;

	void doKeyMove (const CPoint& delta);
	void doKeySize (const CPoint& delta);

	void setUndoManager (UIUndoManager* manager);
	UIUndoManager* getUndoManager ();

	void setSelection (UISelection* selection);
	UISelection* getSelection ();
	
	void setGridProcessor (IGridProcessor* grid);

	void setupColors (const IUIDescription* description);
	
	static IdStringPtr kMsgAttached;
	static IdStringPtr kMsgRemoved;
protected:
	enum class MouseEditMode {
		NoEditing,
		DragEditing,
		SizeEditing,
		LassoSelection,
		WaitDrag,
		WaitLasso,
	};

	enum class MouseSizeMode {
		None,
		BottomRight,
		BottomLeft,
		TopRight,
		TopLeft,
		Left,
		Right,
		Top,
		Bottom
	};

	void updateSize ();
	void invalidSelection ();
	MouseSizeMode selectionHitTest (const CPoint& where, CView** resultView);
	bool hitTestSubViews (const CPoint& where, const Event& event) override;
	CMouseEventResult onMouseDown (CPoint &where, const CButtonState& buttons) override;
	CMouseEventResult onMouseUp (CPoint &where, const CButtonState& buttons) override;
	CMouseEventResult onMouseMoved (CPoint &where, const CButtonState& buttons) override;
	CMouseEventResult onMouseExited (CPoint& where, const CButtonState& buttons) override;
	CMessageResult notify (CBaseObject* sender, IdStringPtr message) override;
	void onKeyboardEvent (KeyboardEvent& event) override;

	std::vector<CView*> findChildsInArea (CViewContainer* view, CRect r) const;

	void doDragEditingMove (CPoint& where);
	void doSizeEditingMove (CPoint& where);
	void onDoubleClickEditing (CView* view);

	void startDrag (CPoint& where);
	SharedPointer<UISelection> getSelectionOutOfDrag (IDataPackage* drag) const;

	SharedPointer<IDropTarget> getDropTarget () override;
	bool onDrop (DragEventData data) override;
	DragOperation onDragEnter (DragEventData data) override;
	void onDragLeave (DragEventData data) override;
	DragOperation onDragMove (DragEventData data) override;

	void draw (CDrawContext *pContext) override;
	void drawRect (CDrawContext *pContext, const CRect& updateRect) override;
	CView* getViewAt (const CPoint& p, const GetViewOptions& options = GetViewOptions ()) const override;
	CViewContainer* getContainerAt (const CPoint& p, const GetViewOptions& options = GetViewOptions ().deep ()) const override;
	bool advanceNextFocusView (CView* oldFocus, bool reverse) override;
	void onMouseWheelEvent (MouseWheelEvent& event) override;
	void onZoomGestureEvent (ZoomGestureEvent& event) override;

	void looseFocus () override;
	void takeFocus () override;
	bool removed (CView* parent) override;
	bool attached (CView* parent) override;

	bool editing {true};
	bool autosizing {true};
	bool inlineAttrTextEditOpen {false};
	MouseEditMode mouseEditMode {MouseEditMode::NoEditing};
	MouseSizeMode mouseSizeMode {MouseSizeMode::None};
	CPoint mouseStartPoint;
 
	SharedPointer<UIUndoManager> undoManger;
	SharedPointer<UISelection> selection;
	SharedPointer<UISelection> dragSelection;
	UIDescription* description {nullptr};
	SharedPointer<IGridProcessor> gridProcessor;
	
	UIEditViewInternal::UIHighlightView* highlightView {nullptr};
	CLayeredViewContainer* overlayView {nullptr};
	UICrossLines* lines {nullptr};
	ViewSizeChangeOperation* moveSizeOperation {nullptr};
	SharedPointer<CVSTGUITimer> editTimer;
	DragStartMouseObserver dragStartMouseObserver;
	
	CColor crosslineForegroundColor;
	CColor crosslineBackgroundColor;
	CColor lassoFillColor;
	CColor lassoFrameColor;
	CColor viewHighlightColor;
	CColor viewSelectionColor;

	struct ViewAddedObserver;
	std::unique_ptr<ViewAddedObserver> editingViewAddedObserver;
	void disableExternalViewsOnInlineEditing (bool state);
};

} // VSTGUI

#endif // VSTGUI_LIVE_EDITING
