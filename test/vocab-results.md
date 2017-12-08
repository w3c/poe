
# Final Implementation Report for ODRL Vocabulary Test Cases 

## CR-VE-17: The ontology documents can be parsed without errors by RDF Schema validators

The [ODRL Ontology](http://w3c.github.io/poe/vocab/ODRL22.ttl) passes validation by the following applications:
* [Protege](https://protege.stanford.edu/)  Version 5.2.0 (MacOSX)
* [RDF Raptor Library](http://librdf.org/raptor/) (also used to generate the specification from the OWL ontology)

## CR-VE-18: The ontology is internally consistent with respect to domains, ranges, inverses, and any other ontology features specified 						

The [ODRL Ontology](http://w3c.github.io/poe/vocab/ODRL22.ttl) is found consistent by the following applications:
* [Protege](https://protege.stanford.edu/) Version 5.2.0 (MacOSX) returns "Ontology is coherent and consistent" from "Debug Ontology" service.
* [RDF Triple-Checker](http://graphite.ecs.soton.ac.uk/checker/) returns no errors

## CR-VE-19: The JSON-LD context document can be parsed without errors by JSON-LD validators			

The [ODRL JSON-LD Context](http://w3c.github.io/poe/vocab/ODRL22.jsonld) passes validation by the following applications:
* [Google Structured Data Testing Tool](https://search.google.com/structured-data/testing-tool)
* [JSON-LD Playground](https://json-ld.org/playground/)

## CR-VE-20: The JSON-LD context document can be used to convert JSON-LD serialized Policies into RDF triples

All of the JSON-LD examples in the ODRL Information Model have been successfully converted from JSON-LD to RDF with the following tools:
* [EasyRDF](http://www.easyrdf.org/converter)
* [RDF Translator](http://rdf-translator.appspot.com/)
* [RDF Distiller](http://rdf.greggkellogg.net/distiller?command=serialize)
* [JSON-LD Playground](https://json-ld.org/playground/)
