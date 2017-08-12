<?php

/*

Adapted from yvesr's phpspecgen:

https://github.com/motools/musicontology.com/blob/master/docs/phpspecgen.php

which is derived from njh's:

https://github.com/njh/phpspecgen

*/

require_once(dirname(__FILE__) . '/easyrdf/lib/EasyRdf.php');
require_once(dirname(__FILE__) . '/classes.php');

$err = fopen('php://stderr', 'w');
if(count($argv) < 3 || count($argv) > 5)
{
	fprintf($err, "Usage: %s FILE.ttl URI [BASENAME [TEMPLATE]]\n", $argv[0]);
	exit(1);
}

$template = 'template.phtml';
$basename = null;
if(count($argv) > 3)
{
	$basename = $argv[3];
}
if(count($argv) > 4)
{
	$template = $argv[4];
}

# Extra namespaces we use
EasyRdf_Namespace::set('odrl', 'http://www.w3.org/ns/odrl/2/');
EasyRdf_Namespace::set('skos', 'http://www.w3.org/2004/02/skos/core#');
EasyRdf_Namespace::set('xsd', 'http://www.w3.org/2001/XMLSchema#');
EasyRdf_Namespace::set('dcterms', 'http://purl.org/dc/terms/');
EasyRdf_Namespace::set('vcard', 'http://www.w3.org/2006/vcard/ns#');
EasyRdf_Namespace::set('foaf', 'http://xmlns.com/foaf/0.1/');
EasyRdf_Namespace::set('schema', 'http://schema.org/');
EasyRdf_Namespace::set('cc', 'https://creativecommons.org/ns#');

$uri = $argv[2];
$graph = new EasyRdf_Graph($uri);
$graph->parseFile($argv[1], 'turtle', $uri);
$vocab = $graph->get('owl:Ontology', '^rdf:type');
$vocab->basename = $basename;
$vocab->termTemplatePath = dirname($template) . '/terms';

if (!isset($vocab))
{
	fprint($err, "%s: No OWL ontologies defined at that URL.\n", $argv[0]);
	exit(1);
}
if(!file_exists($template))
{
	fprintf($err, "%s: cannot find template '%s'\n", $argv[0], $template);
	exit(1);
}

require($template);

