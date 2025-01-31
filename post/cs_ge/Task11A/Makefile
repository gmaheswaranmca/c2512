# Subdirectories
DIR_APP = Client
DIR_TEST = Test

# Default target
.PHONY: all
all:
	@echo "Usage: make <target>"
	@echo "Available targets: app-build, app, app-clean, app-clean-all, test-build, test, test-clean, clean-all"

# Build the App
.PHONY: app-build
app-build:
	@echo "Building App..."
	$(MAKE) -C $(DIR_APP) all

# Build the App	
.PHONY: app-clean
app-clean:
	@echo "Clean App..."
	$(MAKE) -C $(DIR_APP) clean

# Build the App	
.PHONY: app-clean-all
app-clean-all:
	@echo "Clean App and Data..."
	$(MAKE) -C $(DIR_APP) clean cldat
# Run the App
.PHONY: app
app:
	@echo "Run App..."
	$(MAKE) -C $(DIR_APP) run

# Build the LibSun static library
.PHONY: test-build
test-build:
	@echo "Building Test..."
	$(MAKE) -C $(DIR_TEST) all

# Build the LibSun static library
.PHONY: test-clean
test-clean:
	@echo "Clean Test..."
	$(MAKE) -C $(DIR_TEST) clean

# Build the LibSun static library
.PHONY: test
test:
	@echo "Run Test..."
	$(MAKE) -C $(DIR_TEST) test

# Clean all subprojects
.PHONY: clean-all
clean-all:
	@echo "Cleaning all subprojects..."
	$(MAKE) -C $(DIR_TEST) clean
	$(MAKE) -C $(DIR_APP) clean cldat
