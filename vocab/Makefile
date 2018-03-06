TOP = .

RAPPER ?= ./raptor2-2.0.15/utils/rapper
PHP ?= php

NSURI = http://www.w3.org/ns/odrl/2/

ALL = ODRL22.rdf ODRL22.nt index.html

all: $(ALL)

clean:
	rm -f $(ALL)

%.rdf: %.ttl
	$(RAPPER) -i turtle -o rdfxml-abbrev $< > $@

%.nt: %.ttl
	$(RAPPER) -i turtle -o ntriples $< > $@

index.html: ODRL22.ttl $(TOP)/tools/phpspecgen.php $(TOP)/tools/classes.php template.phtml
	php -f $(TOP)/tools/phpspecgen.php -- $< '$(NSURI)' ODRL22 'template.phtml' > $@
