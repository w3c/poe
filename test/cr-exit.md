# CR Exit Criteria

For this specification to be advanced to Proposed Recommendation, there must be at least two independent implementations of each feature described below. Each feature may be implemented by a different set of products, and there is no requirement that any single product implement every feature.

For the purposes of evaluating exit criteria, the following are considered as features:

* A Set/Offer/Agreement Policy type with required properties.
* A Policy that uses a Profile identifier (it understands)
* A Policy that uses a Profile identifier (it does not understand)
* A Policy with an AssetCollection.
* A metadata description of an Asset that refers to a Policy
* A Policy with a PartyCollection.
* A metadata description of a Party that refers to a Policy
* A Policy with a Permission
* A Policy with a Permission including a Constraint
* A Policy with a Permission including a Duty
* A Policy with a Permission including a Duty and a consequence Duty
* A Policy with a Prohibition
* A Policy with a Prohibition including a Constraint
* A Policy with a Prohibition and a remedy Duty
* A Policy with a Permission and a Prohibition
* A Policy with an obligation Duty
* A Policy with a Constraint with all properties
* A Policy with a Logical Constraint
* A Policy with an Asset Constraint
* A Policy with a Party Constraint
* A Compact Policy that requires translation into an Atomic Policy
* A Policy containing metadata
* A Policy that includes Policy inheritance
* A Policy that includes a conflict strategy

ODRL Implementations may publish ODRL Policies and/or consume ODRL Policies.
Each feature, implemented by an ODRL publisher, must produce valid ODRL policies.
Each feature, implemented by an ODRL consumers, must be evaluated to produce an outcome indicating the effective state of the Policy rules.

Software that does not alter its behavior in the presence or lack of a given feature is not deemed to implement that feature for the purposes of exiting the Candidate recommendation phase.

