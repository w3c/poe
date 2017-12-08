* Process document's relevant URL: https://www.w3.org/2017/Process-20170301/#last-call
* Transition requirements: https://www.w3.org/Guide/transitions?profile=CR&cr=new
* Mail to be sent to: ralph@w3.org, plh@w3.org, cc to timbl@w3.org, w3t-comm@w3.org, chairs@w3.org, team-poe-chairs@w3.org

Request sent on Sept 14: https://lists.w3.org/Archives/Member/chairs/2017JulSep/0150.html


---

Philippe, Ralph,

The  Permissions & Obligations Expression Working Group requests transition to CR status for two specifications on ODRL. The publication is planned for the 2017-09-26; the documents are follows:

 * ODRL Information Model
 * ODRL Vocabulary & Expression


(1) Document title, URIs, Abstract and Status
=============================================

ODRL Information Model
----------------------

- Version ready to be published
	https://w3c.github.io/poe/model/
- Final /TR URI when it gets published
	https://www.w3.org/TR/2017/CR-odrl-model-20170926/

Abstract:

The Open Digital Rights Language (ODRL) is a policy expression language that provides a flexible and interoperable information model, vocabulary, and encoding mechanisms for representing statements about the usage of content and services. The ODRL Information Model describes the underlying concepts, entities, and relationships that form the foundational basis for the semantics of the ODRL policies.

Policies are used to represent permitted and prohibited actions over a certain asset, as well as the obligations required to be meet by stakeholders. In addition, policies may be limited by constraints (e.g., temporal or spatial constraints) and duties (e.g. payments) may be imposed on permissions. 

Status:
	http://w3c.github.io/poe/model/#sotd

ODRL Vocabulary & Expression
----------------------------

- Version ready to be published
	http://w3c.github.io/poe/vocab/
- Final /TR URI when it gets published
	http://www.w3.org/TR/2017/CR-odrl-vocab-20170926/

Abstract:

The Open Digital Rights Language (ODRL) is a policy expression language that provides a flexible and interoperable information model, vocabulary, and encoding mechanisms for representing statements about the usage of content and services. The ODRL Vocabulary and Expression describes the terms used in ODRL policies and how to encode them.

Status:
	http://w3c.github.io/poe/vocab/#sotd


(2)  Record of the decision to request the transition
=====================================================

	https://www.w3.org/2017/09/14-poe-minutes.html#resolution01

(3) Record of Changes
=====================

The separate sections of each document record the noteworthy changes:

    http://w3c.github.io/poe/model/#changes
    http://w3c.github.io/poe/vocab/#changes


(4) Evidence that the document satisfies group's requirements
===============================================================

The main input to this Working Group was the ODRL family of documents, developed by the ODRL Community Group:

	https://www.w3.org/community/odrl/

which is widely deployed (and most implementations are now converting to the output of this Working Group). An additional requirement document was published by the working group:

	POE Use Cases and Requirements
	https://www.w3.org/TR/poe-ucr/

Which has an evolving Editor's draft

    https://w3c.github.io/poe/ucr/

The final output of the Working Group takes into account these requirements in the way the ODRL has been reused; the changes, compared to the Community Group ODRL model, are documented at:

    https://w3c.github.io/poe/model/#cgrel
    https://w3c.github.io/poe/vocab/#community

In particular, the charter

	https://www.w3.org/2016/poe/charter

Identified the following list of recommendation track deliverables in the charter:

1. "A technology-neutral permissions and obligations information model (Recommendation)"
2. "A vocabulary for machine-readable expressions of permissions and obligations, and methods for their discovery (Recommendation)"
3. "Mapping of the model and terms in XML (Recommendation)"
4. "Mapping of the model and terms in RDF/OWL, with examples in Turtle and JSON-LD (Recommendation)"
5. "Mapping of the model and terms in JSON (Recommendation)"

These are fulfilled as follows:

1. Recommendation #1 (information model) is fulfilled by the ODRL Information Model Document.
2. Recommendations #2 (vocabulary), #3 (XML) partially, and #4 (RDF/OWL, turtle, JSON-LD) are jointly covered by the ODRL Vocabulary & Expression Document. That document defines all the terms, classes, properties, etc, in terms of RDF, with a formal RDF/OWL ontology defined in the https://www.w3.org/ns/odrl/2/ namespace. The RDF/XML, Turtle, and JSON-LD serializations is not defined by this Working Group, they are just applications of the relevant W3C Recommendations. Note that all the examples in the documents are in JSON-LD
3. A direct mapping to XML (i.e., non RDF/XML) is _not_ fulfilled as a Recommendation due to a lack of necessary interest, but is included - non-normativley - as an appendix in the ODRL Vocabulary & Expression Document.
4. A direct mapping JSON (i.e., non JSON-LD) is _not_ fulfilled, the Working Group decided that, with the presence of JSON-LD, there is no need to have a separate JSON mapping that would look almost exactly the same.

(5) Dependencies
================

There are no problematic dependencies in these documents (other candidate recommendations, rescinded recommendations, etc.)

(6) Evidence that the document has received wide review and that issues have  been formally addressed
=================================================================================================

The group has received and recorded a number of issues; additionally, when the Group issued a Working Drafts on the 23 February 2017, it also explicitly asked for a wide review (declaring that version as some sort of a virtual LC). 

The list of groups/orgs/individuals the "wide review" was sent to:
    https://www.w3.org/2016/poe/wiki/Deliverables
	 
All the comments coming up to this transition have been addressed and resolved satisfactorily:

All issues (removing admin, postponed, testing, etc. issues):

	https://github.com/w3c/poe/issues?utf8=%E2%9C%93&q=is%3Aissue%20

A significant amount of those came from outside the Working Group:

    https://github.com/w3c/poe/issues?page=1&q=is%3Aissue+label%3A%22Wide+Review%22&utf8=%E2%9C%93

All open issues currently:

	https://github.com/w3c/poe/issues
	
(These are all related to NOTES, not the REC-track documents.)

The WG explicitly asked review from Internationalization, Accessibility, Privacy, and Security. It has received, and handled comments from I18N:

    https://github.com/w3c/poe/issues/212
    https://github.com/w3c/poe/issues/213
    https://github.com/w3c/poe/issues/214

Decisions on the issues, answers to, and responses from commenter are all registered in the issue threads.

(7) Objections
==============

There were no formal objections.

(8) Features marked as "at risk"
================================

None.

(9) Patent disclosures
======================

No patent disclosures for these documents at the moment:

	https://www.w3.org/2004/01/pp-impl/87755/exclude

(10)  Implementation information and testing
============================================

The working group intends to  issue a call for implementations to demonstrate the validity of the specifications. The CR Exit Criteria are documented at

   https://w3c.github.io/poe/model/#cr-exit
   https://w3c.github.io/poe/vocab/#cr-exit

A description of the test suite (which will evolve during the CR period) and how implementors should run them is here:

    https://github.com/w3c/poe/blob/gh-pages/test/test-regime.md

The Working Group maintains a separate page for implementations:

	https://github.com/w3c/poe/blob/gh-pages/test/implementors.md

Thanks

Renato Iannella and Benedict Whittam Smith, Working Group Chairs
Ivan Herman, W3C Team Contact
