.PHONY: all clean lint

all: README.md
	@echo Build result: OK

SOURCE_FILES := $(wildcard UVA/Volume_*/*.cpp)
SOURCE_DIRS := UVA/ $(wildcard UVA/Volume_*/)

summary.json: generate_summary.py $(SOURCE_FILES) $(SOURCE_DIRS)
	@$(MAKE) -s lint
	python generate_summary.py

README.md: generate_readme.py README.template.md summary.json
	python generate_readme.py

lint:
	@clang-format --dry-run --Werror $(SOURCE_FILES)
	@echo 'OK: Lint check passed'

clean:
	rm -f summary.json README.md
