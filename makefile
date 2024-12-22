# Define subdirectories
SUBDIRS = Machine-Level_Representation_of_Program float

# Default target
all:
	for dir in $(SUBDIRS); do \
	    $(MAKE) -C $$dir; \
	done

# Clean target
clean:
	for dir in $(SUBDIRS); do \
	    $(MAKE) -C $$dir clean; \
	done
