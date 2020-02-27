AUX_SOURCE_DIRECTORY(. src_files)

ADD_EXECUTABLE(dsp-ctrl ${src_files})

INSTALL(TARGETS dsp-ctrl
	RUNTIME DESTINATION bin
)
