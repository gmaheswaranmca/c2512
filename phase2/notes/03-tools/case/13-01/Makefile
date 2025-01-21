# Subdirectories
DIR_LIBSUN = LibSun
DIR_APP = App
DIR_LIBSUNTEST = LibSunTest

# Default target
.PHONY: all
all:
	@echo "Usage: make <target>"
	@echo "Available targets: libsun, app, libsun-test, clean-all, run-app, libsun-test-gdb, debug-app "

# Build the LibSun static library
.PHONY: libsun
libsun:
	@echo "Building LibSun..."
	$(MAKE) -C $(DIR_LIBSUN) all

# Build the App executable
.PHONY: app
app:
	@echo "Building App..."
	$(MAKE) -C $(DIR_APP) all

# Build and run tests for LibSun
.PHONY: libsun-test
libsun-test:
	@echo "Building and testing LibSun..."
	$(MAKE) -C $(DIR_LIBSUNTEST) all
	$(MAKE) -C $(DIR_LIBSUNTEST) test
libsun-test-debug:
	@echo "Building and debugging LibSun..."
	$(MAKE) -C $(DIR_LIBSUNTEST) all
	$(MAKE) -C $(DIR_LIBSUNTEST) debug
# Run the App executable
.PHONY: run-app
run-app: 
	@echo "Running App..."
	$(MAKE) -C $(DIR_APP) run
debug-app: 
	@echo "debugging App..."
	$(MAKE) -C $(DIR_APP) debug
# Clean all subprojects
.PHONY: clean-all
clean-all:
	@echo "Cleaning all subprojects..."
	$(MAKE) -C $(DIR_LIBSUN) clean
	$(MAKE) -C $(DIR_APP) clean
	$(MAKE) -C $(DIR_LIBSUNTEST) clean
