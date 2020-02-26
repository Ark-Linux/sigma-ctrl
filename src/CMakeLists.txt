AUX_SOURCE_DIRECTORY(. src_files)

ADD_EXECUTABLE(dsp-test ${src_files})

INSTALL(TARGETS dsp-test
	RUNTIME DESTINATION bin
)
