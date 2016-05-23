RAPPER ?= rapper

ALL = \
	example1.rdf example1.nt \
	example1a.rdf example1a.nt \
	example2.rdf example2.nt \
	example3.rdf example3.nt \
	example4.rdf example4.nt \
	example5.rdf example5.nt \
	example6.rdf example6.nt \
	example7.rdf example7.nt \
	example8.rdf example8.nt \
	example9.rdf example9.nt \
	example10.rdf example10.nt \
	example11.rdf example11.nt

all: $(ALL)

clean:
	rm -f $(ALL)

%.rdf: %.ttl
	$(RAPPER) -i turtle -o rdfxml-abbrev $< > $@

%.nt: %.ttl
	$(RAPPER) -i turtle -o ntriples $< > $@
