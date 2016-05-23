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
EasyRdf_Namespace::set('oma', 'http://www.openmobilealliance.com/oma-dd/');
EasyRdf_Namespace::set('onix', 'http://www.editeur.org/onix-pl/');

$uri = $argv[2];
$graph = new EasyRdf_Graph($uri);
$graph->parseFile($argv[1], 'turtle', $uri);
$vocab = $graph->get('owl:Ontology', '^rdf:type');
$vocab->basename = $basename;
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

