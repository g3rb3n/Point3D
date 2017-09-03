.PHONY: all test upload monitor

test-nano:
	pio test -e nano --verbose

test-d1mini:
	pio test -e d1_mini --verbose

upload-nano:
	pio run -e nano -t upload --verbose

upload-d1mini:
	pio run -e d1_mini -t upload --verbose

monitor:
	pio device monitor
