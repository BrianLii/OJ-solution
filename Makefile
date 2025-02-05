.PHONY: all clean lint

all: README.md
	@echo Build result: OK

SOURCE_FILES := $(wildcard UVA/Volume_*/*.cpp)
SOURCE_DIRS := UVA/ $(wildcard UVA/Volume_*/)

summary.json: generate_summary.py $(SOURCE_FILES) $(SOURCE_DIRS)
	@$(MAKE) -s lint
	python generate_summary.py

README.md: generate_README.py README.template.md summary.json
	python generate_README.py

lint:
	@clang-format --dry-run --Werror $(SOURCE_FILES)
	@echo 'OK: Lint check'

clean:
	rm -f summary.json README.md
