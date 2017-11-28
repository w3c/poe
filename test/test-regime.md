# ODRL Candidate Recommendation - Test Regime

The first purpose of these tests is to help ensure that the requirements expressed in the ODRL Specification can be properly supported by implementors. Does the ODRL Specification work?

Given the answer 'yes', their second purpose is to increase confidence that all implementations are interoperable. 

So this test regime has two objectives:
1. To ensure that each of the features listed in the Exit Criteria can be properly supported by implementors;
2. To ensure interoperability between implementations.


## ODRL 

The ODRL Specification is provided in these two documents:

ODRL Information Model: [https://w3c.github.io/poe/model/](https://w3c.github.io/poe/model/)

ODRL Vocabulary and Expression: [https://w3c.github.io/poe/vocab/#encodings](https://w3c.github.io/poe/vocab/#encodings)

## CR Exit 

The test regime tests the key features identified in the CR Exit Criteria:

[https://w3c.github.io/poe/test/cr-exit](https://w3c.github.io/poe/test/cr-exit)

### ODRL Validation:

The validation tests help ensure that implementations agree on which policies are valid (and which are not) based on the normative part of the specification. The tests should generate a boolean output (valid/invalid) that matches the values provided:

[https://www.w3.org/2016/poe/wiki/Validation](https://www.w3.org/2016/poe/wiki/Validation)

#### SHACL Shapes (for Validation):

The validation tests do not presuppose the use of SHACL Shapes to test for validity. But shapes covering most of the tests are provided for those who want to use them as a validation mechanism:

[https://github.com/w3c/poe/tree/gh-pages/semantics/shacl](https://github.com/w3c/poe/tree/gh-pages/semantics/shacl)


### ODRL Evaluation:

The evaluation tests promote interoperability. Given that two implementations agree as to the state-of-the-world such that they agree on what duties and constraints have been fulfilled and satisfied, then they should also agree on what permissions, prohibitions, and obligations are 'active' (i.e those permissions, prohibitions, and obligations an assignee can exercise or is bound by). 

For each feature of the normative part of the specification, the evaluation tests provide a table of possible states of the duties and constraints contained within an example permission, prohibition, or obligation. The tests should then generate a boolean output (active/inactive) that matches the values provided:

[https://www.w3.org/2016/poe/wiki/Evaluator](https://www.w3.org/2016/poe/wiki/Evaluator)


### Implementors

Implementors of ODRL are invited to provide Implementation Results based on the [CR Exit Criteria ](https://w3c.github.io/poe/test/cr-exit) by filling in the ODRL Google sheet for collecting results [https://goo.gl/iXnonW](https://goo.gl/iXnonW)

The collected Implementation Results are published on this page: [https://w3c.github.io/poe/test/implementors](https://w3c.github.io/poe/test/implementors)
