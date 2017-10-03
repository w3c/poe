# CR Exit Criteria

## [ODRL Information Model CR Exit Criteria](https://www.w3.org/TR/2017/CR-odrl-model-20170926/#cr-exit)

| ID | ODRL Feature | Test Cases |
| ---- | ---- | ----  |
| CR-IM-01 | A Set/Offer/Agreement Policy type with required properties | E12-1 N1 N2 V1 V2 V3 V4 V5 V6 V7 V22  |
| CR-IM-02 | A Policy that utilises an ODRL Profile | V12 V13 V14 V15|
| CR-IM-03 | A Policy with an Asset Collection, including parts | |
| CR-IM-04 | A Policy with a Party Collection, including parts |
| CR-IM-05 | A Policy with a Rule including a constraint property | E13-1/2 E18-1/2 V16 V17 V18 V20 V21 |
| CR-IM-06 | A Policy with a Permission including a duty property | E22-1/2/3/4|
| CR-IM-07 | A Policy with a Permission including a duty and a consequence property | E23-1/2/3/4/5|
| CR-IM-08 | A Policy with a Prohibition | E19-1/2|
| CR-IM-09 | A Policy with a Prohibition including a remedy property |E24-1/2/3 V8 |
| CR-IM-10 | A Policy with an Obligation | E20-1/2 E21-1/2/3/4/5 |
| CR-IM-11 | A Policy with a refinement property on an Action, Asset and Party Collection | E14-1/2  E16-1/2 E17-1/2 V9 V10|
| CR-IM-12 | A Policy with a Logical Constraint | E15-1/2/3/4 V19|
| CR-IM-13 | A Compact Policy that requires translation into an Atomic Policy | N4 N5|
| CR-IM-14 | A Policy containing metadata | |
| CR-IM-15 | A Policy that includes Policy inheritance | N3 V24|
| CR-IM-16 | A Policy that includes a Conflict Strategy | V11 V23|

   
## [ODRL Vocabulary & Expression CR Exit Criteria](https://www.w3.org/TR/2017/CR-odrl-vocab-20170926/#cr-exit)
#### The POE WG will test these criteria with common RDF/JSON-LD tools and services 
| ID | ODRL Feature |
| ------ | ------ |
| CR-VE-17 | The ontology documents can be parsed without errors by RDF Schema validators |
| CR-VE-18 | The ontology is internally consistent with respect to domains, ranges, inverses, and any other ontology features specified |
| CR-VE-19 | The JSON-LD context document can be parsed without errors by JSON-LD validators |
| CR-VE-20 | The JSON-LD context document can be used to convert JSON-LD serialized Policies into RDF triples |