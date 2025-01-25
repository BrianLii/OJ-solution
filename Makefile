.PHONY: all clean lint
all: summary.json README.md lint

SOURCES := $(wildcard UVA_verified/**/*.cpp)

summary.json: summarize.py $(SOURCES)
	python summarize.py

README.md: README.template.md summary.json generate_README.py
	python generate_README.py

lint: $(SOURCES)
	@echo -n "Lint check ... "
	@clang-format --dry-run --Werror $(SOURCES)
	@echo "OK"

clean:
	rm -f summary.json README.md
