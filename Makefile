.PHONY: all clean
all: summary.json README.md

summary.json: summarize.py
	python summarize.py

README.md: README.template.md summary.json generate_README.py
	python generate_README.py

clean:
	rm -f summary.json README.md
