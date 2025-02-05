.PHONY: all clean lint

all: README.md
	@echo Build result: OK

SOURCE_FILES := $(wildcard UVA/Volume_*/*.cpp)
SOURCE_DIRS := UVA/ $(wildcard UVA/Volume_*/)

summary.json: summarize.py $(SOURCE_FILES) $(SOURCE_DIRS)
	@$(MAKE) -s lint
	python summarize.py

README.md: generate_README.py README.template.md summary.json
	python generate_README.py

lint:
	@clang-format --dry-run --Werror $(SOURCE_FILES)
	@echo 'Lint check ... OK'

clean:
	rm -f summary.json README.md
