.PHONY: all summary.json lint clean
all: lint summary.json README.md

SOURCES := $(wildcard UVA/**/*.cpp)

summary.json: summarize.py
	python summarize.py

README.md: README.template.md summary.json generate_README.py
	python generate_README.py

lint: $(SOURCES)
	@echo -n "Lint check ... "
	@clang-format --dry-run --Werror $(SOURCES)
	@echo "OK"

clean:
	rm -f summary.json README.md
