RAPPER ?= rapper

ALL = \
	example1.rdf example1.nt example1.xml \
	example1a.rdf example1a.nt \
	example2.rdf example2.nt example2.xml\
	example3.rdf example3.nt example3.xml\
	example4.rdf example4.nt example4.xml\
	example5.rdf example5.nt example5.xml\
	example6.rdf example6.nt example6.xml\
	example7.rdf example7.nt example7.xml\
	example8.rdf example8.nt example8.xml\
	example9.rdf example9.nt example9.xml\
	example10.rdf example10.nt example10.xml\
	example11.rdf example11.nt example11.xml

all: $(ALL)

clean:
	rm -f $(ALL)

%.rdf: %.ttl
	$(RAPPER) -i turtle -o rdfxml-abbrev $< > $@

%.nt: %.ttl
	$(RAPPER) -i turtle -o ntriples $< > $@
