
set(validator_sources
    ${SDK_ROOT}/public.sdk/source/common/memorystream.cpp
    ${SDK_ROOT}/public.sdk/source/main/moduleinit.cpp
    ${SDK_ROOT}/public.sdk/source/main/moduleinit.h
    ${SDK_ROOT}/public.sdk/source/vst/moduleinfo/moduleinfoparser.cpp
    ${SDK_ROOT}/public.sdk/source/vst/moduleinfo/moduleinfoparser.h
    ${SDK_ROOT}/public.sdk/source/vst/hosting/test/connectionproxytest.cpp
    ${SDK_ROOT}/public.sdk/source/vst/hosting/test/eventlisttest.cpp
    ${SDK_ROOT}/public.sdk/source/vst/hosting/test/hostclassestest.cpp
    ${SDK_ROOT}/public.sdk/source/vst/hosting/test/parameterchangestest.cpp
    ${SDK_ROOT}/public.sdk/source/vst/hosting/test/pluginterfacesupporttest.cpp
    ${SDK_ROOT}/public.sdk/source/vst/hosting/test/processdatatest.cpp
    ${SDK_ROOT}/public.sdk/source/vst/hosting/plugprovider.cpp
    ${SDK_ROOT}/public.sdk/source/vst/hosting/plugprovider.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/busactivation.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/busactivation.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/busconsistency.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/busconsistency.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/businvalidindex.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/businvalidindex.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/checkaudiobusarrangement.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/checkaudiobusarrangement.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/scanbusses.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/scanbusses.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/sidechainarrangement.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/bus/sidechainarrangement.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/editorclasses.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/editorclasses.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/midilearn.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/midilearn.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/midimapping.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/midimapping.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/plugcompat.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/plugcompat.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/scanparameters.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/scanparameters.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/suspendresume.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/suspendresume.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/terminit.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/general/terminit.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/noteexpression/keyswitch.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/noteexpression/keyswitch.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/noteexpression/noteexpression.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/noteexpression/noteexpression.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/automation.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/automation.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/process.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/process.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processcontextrequirements.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processcontextrequirements.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processformat.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processformat.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processinputoverwriting.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processinputoverwriting.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processtail.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processtail.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processthreaded.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/processthreaded.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/silenceflags.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/silenceflags.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/silenceprocessing.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/silenceprocessing.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/speakerarrangement.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/speakerarrangement.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/variableblocksize.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/processing/variableblocksize.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/state/bypasspersistence.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/state/bypasspersistence.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/state/invalidstatetransition.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/state/invalidstatetransition.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/state/repeatidenticalstatetransition.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/state/repeatidenticalstatetransition.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/state/validstatetransition.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/state/validstatetransition.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/testbase.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/testbase.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/unit/checkunitstructure.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/unit/checkunitstructure.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/unit/scanprograms.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/unit/scanprograms.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/unit/scanunits.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/unit/scanunits.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/vststructsizecheck.h
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/vsttestsuite.cpp
    ${SDK_ROOT}/public.sdk/source/vst/testsuite/vsttestsuite.h
    ${SDK_ROOT}/public.sdk/source/vst/utility/testing.cpp
    ${SDK_ROOT}/public.sdk/source/vst/utility/testing.h
    source/main.cpp
    source/usediids.cpp
    source/validator.cpp
    source/validator.h
    source/testsuite.h
)

if(SMTG_MAC)
    set(validator_sources
        ${validator_sources}
        ${SDK_ROOT}/public.sdk/source/vst/hosting/module_mac.mm
    )
    set_source_files_properties(
        "${SDK_ROOT}/public.sdk/source/vst/hosting/module_mac.mm" PROPERTIES
        COMPILE_FLAGS "-fobjc-arc"
    )
elseif(SMTG_LINUX)
    set(validator_sources
        ${validator_sources}
        ${SDK_ROOT}/public.sdk/source/vst/hosting/module_linux.cpp
    )
elseif(SMTG_WIN)
    set(validator_sources
        ${validator_sources}
        ${SDK_ROOT}/public.sdk/source/vst/hosting/module_win32.cpp
    )
endif(SMTG_MAC)

set(target validator)
add_executable(${target} ${validator_sources})
if(SDK_IDE_HOSTING_EXAMPLES_FOLDER)
    set_target_properties(${target}
        PROPERTIES
            ${SDK_IDE_HOSTING_EXAMPLES_FOLDER}
    )
endif(SDK_IDE_HOSTING_EXAMPLES_FOLDER)
target_compile_features(${target}
    PUBLIC
        cxx_std_17
)
target_link_libraries(${target}
    PRIVATE
        sdk_hosting
)
smtg_target_codesign(${target})
smtg_target_setup_universal_binary(${target})
if(APPLE AND NOT XCODE)
    find_library(COCOA_FRAMEWORK Cocoa)
    target_link_libraries(${target}
        PRIVATE
            ${COCOA_FRAMEWORK}
    )
endif(APPLE AND NOT XCODE)

#####################################################
if(SMTG_RUN_VST_VALIDATOR)
    ####################
    # Workaround for Xcode 15 not allowing to add adhoc_codesign linker setting
    ####################
    if(SMTG_MAC AND XCODE_VERSION VERSION_GREATER_EQUAL 15)
        add_custom_command(
            TARGET ${target} POST_BUILD
            COMMENT "[SMTG] Adhoc codesign workaround for Xcode 15"
            COMMAND codesign --force --verbose --sign -
                "$<TARGET_FILE:${target}>"
        )
	endif()
    add_custom_command(TARGET ${target} POST_BUILD
	    COMMAND $<TARGET_FILE:${target}> "-selftest"
    )
endif(SMTG_RUN_VST_VALIDATOR)
