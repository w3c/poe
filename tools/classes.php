<?php

    class Phpspecgen_Term extends EasyRdf_Resource
    {
        public function termLink() {
            $name = htmlspecialchars($this->localName());
            return "<a href=\"#term-$name\">$name</a>";
        }

		protected function addPropertyList(&$list, $values, $skip)
		{
			foreach($values as $value)
			{
				$k = strval($value);
				if(in_array(strval($value), $skip))
				{
					continue;
				}
				if($value instanceof EasyRdf_Collection)
				{
					$this->addPropertyList($list, $value, $skip);
					continue;
				}
				if($value instanceof EasyRdf_Resource && $value->isBNode())
				{
					$union = $value->all('owl:unionOf');
					$this->addPropertyList($list, $union, $skip);
					continue;
				}
                if ($value instanceof Phpspecgen_Term)
				{
					$list[$k] = $value->termLink();
                }
				else if ($value instanceof EasyRdf_Resource)
				{
                	$list[$k] = $value->htmlLink($value->shorten());
                }
				else
				{
                    $list[$k] = strval($value);
                }				
			}
		}

        public function propertyList($property, $skip = null) {
            $items = array();
			if(!is_array($skip))
			{
				$skip = array();
			}
			$this->addPropertyList($items, $this->all($property), $skip);
			ksort($items);
            return $items;
        }

        public function propertyRow($title, $property, $skip = null) {
            $items = $this->propertyList($property, $skip);
            if (count($items) > 0) {
                return "<tr><th>$title:</th> <td>".implode(', ', $items)."</td></tr>\n";
            } else {
                return '';
            }
        }
    }

    class Phpspecgen_Class extends Phpspecgen_Term
    {
        public function termType() {
            return 'Class';
        }

        public function inheritedProperties() {
            $properties = array();
            foreach ($this->allParents() as $parent) {
                foreach($parent->all('^rdfs:domain') as $property) {
                    if ($property instanceof Phpspecgen_Term) {
                        array_push($properties, $property->termLink());
                    }
                }
            }
            return $properties;
        }

        protected function allParents($depth=0) {
            $parents = array();
            foreach ($this->all('rdfs:subClassOf') as $parent) {
                if (!$parent instanceof Phpspecgen_Class)
                    continue;
                array_push($parents, $parent);
                if ($depth < 10)
                    $parents = array_merge($parents, $parent->allParents($depth));
            }
            return $parents;
        }
    }

    class Phpspecgen_Property extends Phpspecgen_Term
    {
        public function termType() {
            return 'Property';
        }
    }

    class Phpspecgen_ConceptScheme extends Phpspecgen_Term
    {
        public function termType() {
            return 'Concept scheme';
        }
    }

    class Phpspecgen_Individual extends Phpspecgen_Term
    {
        public function termType() {
            return 'Named individual';
        }
    }

    class Phpspecgen_Concept extends Phpspecgen_Term
    {
        public function termType() {
            return 'Concept';
        }
    }

    class Phpspecgen_Vocab extends EasyRdf_Resource
    {
    	public $revision = null;
		public $basename = null;

        protected function propertyDefinition($title, $property) {
            $values = $this->all($property);
            if (count($values) < 1)
                return '';

            $html = array();
            foreach($values as $value) {
                if ($value instanceof EasyRdf_Literal) {
                    array_push($html, htmlspecialchars($value));
                } else if ($value->get('foaf:homepage')) {
                    array_push($html, $value->get('foaf:homepage')->htmlLink( $value->label() ));
                } else {
                    if ($value->isBnode()) {
                        array_push($html, htmlspecialchars($value->label()) );
                    } else {
                        array_push($html, $value->htmlLink($value->label()) );
                    }
                }
            }

            return "<dt>$title</dt><dd>".implode(', ', array_unique($html))."</dd>\n";
        }

        public function htmlHeader() {
        	$this->revision = $this->get('owl:versionInfo');
            $html = "<h1>".htmlspecialchars($this->label())."</h1>\n";
            $html .= "<em>".htmlspecialchars($this->get('dc:description|dc11:description|rdfs:comment'))."</em>\n";

            $html .= "<dl>\n";
			if(strlen($this->basename))
           	{
           		$html .= "<dt>This version</dt><dd><a href=\"" . $this->uri . $this->basename . "\">" . $this->uri . $this->basename . "</a></dd>\n";
           	}
           	$html .= "<dt>Latest version</dt><dd>".$this->htmlLink()."</dd>\n";
           	$html .= $this->propertyDefinition('Created', 'dc:created|dc11:created');
            $html .= $this->propertyDefinition('Date', 'dc:date|dc11:date|dc:issued|dc11:issued');
            $html .= $this->propertyDefinition('Revision', 'owl:versionInfo');
            $html .= $this->propertyDefinition('Authors', 'foaf:maker|dc:creator|dc11:creator');
            $html .= $this->propertyDefinition('Contributors', 'dc:contributor|dc11:contributor');
            $html .= "</dl>\n";
            return $html;
        }

        public function htmlSummaryOfTerms() {
            $html = "<h2 id=\"sec-summary\">Summary of Terms</h2>\n";
			$classes = array();
            $classCount = 0;
			$props = array();
            $propertyCount = 0;
			$schemes = array();
			$schemeCount = 0;
			$concepts = array();
			$conceptCount = 0;
			$individuals = array();
			$individualCount = 0;
            foreach($this->all("^rdfs:isDefinedBy") as $term) {
				if(method_exists($term, 'label'))
				{
					$k = strval($term->label());
				}
				else
				{
					$k = strval($term->localName());
				}
                if ($term instanceof Phpspecgen_Class)
				{
					$classes[$k] = $term->termLink();
                    $classCount++;
				}
                else if ($term instanceof Phpspecgen_Property)
				{
					$props[$k] = $term->termLink();
                    $propertyCount++;
				}
				else if ($term instanceof Phpspecgen_ConceptScheme)
				{
					$schemes[$k] = $term->termLink();
					$schemeCount++;
				}
				else if ($term instanceof Phpspecgen_Concept)
				{
					$concepts[$k] = $term->termLink();
					$conceptCount++;
				}
				else if ($term instanceof Phpspecgen_Individual)
				{
					$individuals[$k] = $term->termLink();
					$individualCount++;
				}
            }
			ksort($classes);
			ksort($props);
			ksort($schemes);
			ksort($concepts);
			ksort($individuals);
            $html .= "<p>This vocabulary defines ";
			$counts = array();
			if($classCount > 0)
			{
				$counts[] = ($classCount == 1 ? 'one class' : ($classCount . ' classes'));
			}
			if($propertyCount > 0)
			{
				$counts[] = ($propertyCount == 1 ? 'one property' : ($propertyCount . ' properties'));
			}
			if($schemeCount > 0)
			{
				$counts[] = ($schemeCount == 1 ? 'one concept scheme' : ($schemeCount . ' concept schemes'));
			}
			if($conceptCount > 0)
			{
				$counts[] = ($conceptCount == 1 ? 'one concept' : ($conceptCount . ' concepts'));
			}
			if($individualCount > 0)
			{
				$counts[] = ($individualCount == 1 ? 'one named individual' : ($individualCount . ' named individuals'));
			}
			$sub = array_slice($counts, 0, -1);
			if(count($counts) > 1)
			{
				$last = ' and ' . array_pop($counts);
			}
			else
			{
				$last = '';
			}
			$html .= implode(', ', $sub) . $last . '.'; 
            $html .= "</p>\n";

			$html .= '<dl>';
			if($classCount)
			{
				$html .= '<dt>Classes</dt>';
				$html .= '<dd>' . implode('&nbsp;| ', $classes) . '</dd>';
			}
			if($propertyCount)
			{
				$html .= '<dt>Properties</dt>';
				$html .= '<dd>' . implode('&nbsp;| ', $props) . '</dd>';
			}
			if($schemeCount)
			{
				$html .= '<dt>Concept schemes</dt>';
				$html .= '<dd>' . implode('&nbsp;| ', $schemes) . '</dd>';
			}
			if($conceptCount)
			{
				$html .= '<dt>Concepts</dt>';
				$html .= '<dd>' . implode('&nbsp;| ', $concepts) . '</dd>';
			}
			if($individualCount)
			{
				$html .= '<dt>Named individuals</dt>';
				$html .= '<dd>' . implode('&nbsp;| ', $individuals) . '</dd>';
			}
			$html .= '</dl>';
/*
            $html .= "<table>\n";
            $html .= "<tr><th>Term Name</th><th>Type</th><th>Definition</th></tr>\n";
            foreach($this->all("^rdfs:isDefinedBy") as $term) {
                if ($term instanceof Phpspecgen_Term) {
                    $html .= "<tr>";
                    $html .= "<td>".$term->termLink()."</td>";
                    $html .= "<td>".$term->termType()."</td>";
                    $html .= "<td>".$term->getLiteral('rdfs:comment|rdfs:label')."</td>";
                    $html .= "</tr>\n";
                }
            }
            $html .= "</table>\n";
*/
            return $html;
        }

        public function htmlTerms($type, $title) {
            $html = '';
            $id = strtolower(str_replace(' ','-',$title));
            $html .= "<h2 id=\"sec-$id\">$title</h2>\n";
            foreach($this->all("^rdfs:isDefinedBy") as $term) {
                if (!$term instanceof $type)
                    continue;

                $name = htmlspecialchars($term->localName());
                $html .= "<h3 id=\"term-$name\">$name</h3\n";
                $html .= "<p>".htmlspecialchars($term->get('rdfs:comment'))."</p>\n";
                $html .= "<table>\n";
                $html .= "  <tr><th>URI:</th> <td>".$term->htmlLink()."</td></tr>\n";
                $html .= $term->propertyRow("Label", "rdfs:label");
                $html .= $term->propertyRow("Status", "vs:term_status");
				$html .= $term->propertyRow("Equivalent to", "owl:sameAs");
				$html .= $term->propertyRow("Deprecated by", "ont:deprecatedBy");
				$html .= $term->propertyRow("Deprecates", "^ont:deprecatedBy");
                $html .= $term->propertyRow("Sub-classes", "^rdfs:subClassOf");
                $html .= $term->propertyRow("Sub-properties", "^rdfs:subPropertyOf");
                $html .= $term->propertyRow("Narrower terms", "^skos:broaderTransitive");
                $html .= $term->propertyRow("Broader terms", "skos:broaderTransitive");
                $html .= $term->propertyRow("Parent class", "rdfs:subClassOf");
                $html .= $term->propertyRow("Parent property", "rdfs:subPropertyOf");
                $html .= $term->propertyRow("Properties", "^rdfs:domain");
                if ($term instanceof Phpspecgen_Class) {
                    $properties = $term->inheritedProperties();
                    if (count($properties) > 0)
                        $html .= "  <tr><th>Inherited Properties:</th> ".
                                 "<td>".join(', ', $properties)."</td></tr>\n";
                }
                $html .= $term->propertyRow("Range", "rdfs:range");
                $html .= $term->propertyRow("In range of", "^rdfs:range");
                $html .= $term->propertyRow("Domain", "rdfs:domain");
				$html .= $term->propertyRow('Instances', '^rdf:type');
                $html .= $term->propertyRow("See Also", "rdfs:seeAlso");
				if($term instanceof Phpspecgen_Individual || $term instanceof Phpspecgen_Concept)
				{
					$html .= $term->propertyRow('Class', 'rdf:type', array('http://www.w3.org/2004/02/skos/core#Concept', 'http://www.w3.org/2002/07/owl#NamedIndividual'));
				}
				$html .= $term->propertyRow('Concepts', 'skos:hasTopConcept');
				$html .= $term->propertyRow('Concept scheme', '^skos:hasTopConcept');
                $html .= "</table>\n";
                $html .= "</div>\n";
            }
            return $html;
        }

    }

    # Extra namespaces we use
    EasyRdf_Namespace::set('vann', 'http://purl.org/vocab/vann/');
    EasyRdf_Namespace::set('vs', 'http://www.w3.org/2003/06/sw-vocab-status/ns#');
	EasyRdf_Namespace::set('ont', 'http://purl.org/net/ns/ontology-annot#');

    ## Add mappings
    EasyRdf_TypeMapper::set('owl:Ontology', 'Phpspecgen_Vocab');
    EasyRdf_TypeMapper::set('owl:Class', 'Phpspecgen_Class');
    EasyRdf_TypeMapper::set('rdfs:Class', 'Phpspecgen_Class');
    EasyRdf_TypeMapper::set('owl:Property', 'Phpspecgen_Property');
    EasyRdf_TypeMapper::set('owl:DatatypeProperty', 'Phpspecgen_Property');
    EasyRdf_TypeMapper::set('owl:ObjectProperty', 'Phpspecgen_Property');
    EasyRdf_TypeMapper::set('owl:InverseFunctionalProperty', 'Phpspecgen_Property');
    EasyRdf_TypeMapper::set('owl:FunctionalProperty', 'Phpspecgen_Property');
    EasyRdf_TypeMapper::set('rdf:Property', 'Phpspecgen_Property');
    EasyRdf_TypeMapper::set('skos:ConceptScheme', 'Phpspecgen_ConceptScheme');
    EasyRdf_TypeMapper::set('skos:Concept', 'Phpspecgen_Concept');
    EasyRdf_TypeMapper::set('owl:NamedIndividual', 'Phpspecgen_Individual');
