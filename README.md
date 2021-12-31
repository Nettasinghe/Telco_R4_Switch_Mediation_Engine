# Telco_R4_Switch_Mediation_Engine

Switch Mediation Engine for Alcatel MSC R4 CDR format version.

Telecom Switches such as MSCs, GGSNs, SMSCs and VAS servers store subscribers Call Detail Record (CDR) data in encoded formats of either proprietary or ASN.1. Switch Mediation Engine functions as the intermediary between the Telco Network and the Billing System by decoding the CDRs and transforming (amalgamating, stitching and enhancing) them to the input format expected by the Billing System. R4 Mediation Engine decodeds Alcatel MSC CDRs in R4 version (which is proprietary).

mediation.cpp file contains the main method of this module.
