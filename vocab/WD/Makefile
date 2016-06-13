TOP = ../..

RAPPER ?= rapper
PHP ?= php

NSURI = http://www.w3.org/ns/odrl/3/

ALL = ODRL30.rdf ODRL30.nt index.html

all: $(ALL)

clean:
	rm -f $(ALL)

%.rdf: %.ttl
	$(RAPPER) -i turtle -o rdfxml-abbrev $< > $@

%.nt: %.ttl
	$(RAPPER) -i turtle -o ntriples $< > $@

index.html: ODRL30.ttl $(TOP)/tools/phpspecgen.php $(TOP)/tools/classes.php template.phtml
	php -f $(TOP)/tools/phpspecgen.php -- $< '$(NSURI)' ODRL30 'template.phtml' > $@
