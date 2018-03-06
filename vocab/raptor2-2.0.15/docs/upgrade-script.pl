#!/usr/bin/perl -pi~
# Perl script to upgrade raptor2 1.4.21 to 2.0.0


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions
s|^(.*raptor_compare_strings.*)$|/\* WARNING: raptor_compare_strings - deleted. Trivial utility function removed. \*/ $1|g;
s|^(.*raptor_copy_identifier.*)$|/\* WARNING: raptor_copy_identifier - deleted. Use raptor_term_copy() with #raptor_term objects. \*/ $1|g;
s|^(.*raptor_error_handlers_init.*)$|/\* WARNING: raptor_error_handlers_init - deleted. Replaced by generic raptor log mechanism.  See raptor_world_set_log_handler() \*/ $1|g;
s|^(.*raptor_error_handlers_init_v2.*)$|/\* WARNING: raptor_error_handlers_init_v2 - deleted. Replaced by generic raptor log mechanism.  See raptor_world_set_log_handler() \*/ $1|g;
s|^(.*raptor_feature_value_type.*)$|/\* WARNING: raptor_feature_value_type - deleted. Use raptor_world_get_option_description() for the option and access the value_type field. \*/ $1|g;
s|^(.*raptor_finish.*)$|/\* WARNING: raptor_finish - deleted. Use raptor_free_world() with #raptor_world object. \*/ $1|g;
s|^(.*raptor_free_identifier.*)$|/\* WARNING: raptor_free_identifier - deleted. Use raptor_free_term() with #raptor_term objects. \*/ $1|g;
s|^(.*raptor_init.*)$|/\* WARNING: raptor_init - deleted. Use raptor_new_world() to create a new #raptor_world object. \*/ $1|g;
s|^(.*raptor_iostream_get_bytes_written_count.*)$|/\* WARNING: raptor_iostream_get_bytes_written_count - deleted. Deprecated for raptor_iostream_tell(). \*/ $1|g;
s|^(.*raptor_iostream_write_string_turtle.*)$|/\* WARNING: raptor_iostream_write_string_turtle - deleted. Deprecated for raptor_string_python_write(). \*/ $1|g;
s|^(.*raptor_new_identifier.*)$|/\* WARNING: raptor_new_identifier - deleted. Replaced by raptor_new_term_from_blank(), raptor_new_term_from_literal() or raptor_new_term_from_blank() and #raptor_term class. \*/ $1|g;
s|^(.*raptor_new_identifier_v2.*)$|/\* WARNING: raptor_new_identifier_v2 - deleted. Replaced by raptor_new_term_from_blank(), raptor_new_term_from_literal() or raptor_new_term_from_blank() and #raptor_term class. \*/ $1|g;
s|^(.*raptor_ntriples_string_as_utf8_string.*)$|/\* WARNING: raptor_ntriples_string_as_utf8_string - deleted. Deprecated internal debug function. \*/ $1|g;
s|^(.*raptor_ntriples_term_as_string.*)$|/\* WARNING: raptor_ntriples_term_as_string - deleted. Deprecated internal debug function. \*/ $1|g;
s|^(.*raptor_print_ntriples_string.*)$|/\* WARNING: raptor_print_ntriples_string - deleted. Use raptor_string_ntriples_write() with a #raptor_iostream \*/ $1|g;
s|^(.*raptor_print_statement_detailed.*)$|/\* WARNING: raptor_print_statement_detailed - deleted. Deprecated internal function. \*/ $1|g;
s|^(.*raptor_sequence_print_string.*)$|/\* WARNING: raptor_sequence_print_string - deleted. Trivial utility function removed. \*/ $1|g;
s|^(.*raptor_sequence_print_uri.*)$|/\* WARNING: raptor_sequence_print_uri - deleted. Deprecated for raptor_uri_print() \*/ $1|g;
s|^(.*raptor_sequence_set_print_handler.*)$|/\* WARNING: raptor_sequence_set_print_handler - deleted. Use the argument in the raptor_new_sequence() constructor instead. \*/ $1|g;
s|^(.*raptor_sequence_set_print_handler_v2.*)$|/\* WARNING: raptor_sequence_set_print_handler_v2 - deleted. Use the argument in the raptor_new_sequence() constructor instead. \*/ $1|g;
s|^(.*raptor_serializer_set_error_handler.*)$|/\* WARNING: raptor_serializer_set_error_handler - deleted. Replaced by raptor_world_set_log_handler() on the #raptor_world object. \*/ $1|g;
s|^(.*raptor_serializer_set_warning_handler.*)$|/\* WARNING: raptor_serializer_set_warning_handler - deleted. Replaced by raptor_world_set_log_handler() on the #raptor_world object. \*/ $1|g;
s|^(.*raptor_set_error_handler.*)$|/\* WARNING: raptor_set_error_handler - deleted. Replaced by raptor_world_set_log_handler() on the #raptor_world object. \*/ $1|g;
s|^(.*raptor_set_fatal_error_handler.*)$|/\* WARNING: raptor_set_fatal_error_handler - deleted. Replaced by raptor_world_set_log_handler() on the #raptor_world object. \*/ $1|g;
s|^(.*raptor_set_parser_strict.*)$|/\* WARNING: raptor_set_parser_strict - deleted. Replaced by raptor_parser_set_option() with option RAPTOR_OPTION_STRICT \*/ $1|g;
s|^(.*raptor_set_warning_handler.*)$|/\* WARNING: raptor_set_warning_handler - deleted. Replaced by raptor_world_set_log_handler() on the #raptor_world object. \*/ $1|g;
s|^(.*raptor_statement_part_as_counted_string.*)$|/\* WARNING: raptor_statement_part_as_counted_string - deleted. Better done via methods of #raptor_term class such as raptor_term_to_counted_string(). \*/ $1|g;
s|^(.*raptor_statement_part_as_counted_string_v2.*)$|/\* WARNING: raptor_statement_part_as_counted_string_v2 - deleted. Better done via methods of #raptor_term class such as raptor_term_to_counted_string(). \*/ $1|g;
s|^(.*raptor_statement_part_as_string.*)$|/\* WARNING: raptor_statement_part_as_string - deleted. Better done via methods of #raptor_term class such as raptor_term_to_string(). \*/ $1|g;
s|^(.*raptor_statement_part_as_string_v2.*)$|/\* WARNING: raptor_statement_part_as_string_v2 - deleted. Better done via methods of #raptor_term class such as raptor_term_to_string(). \*/ $1|g;
s|^(.*raptor_uri_get_handler.*)$|/\* WARNING: raptor_uri_get_handler - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_uri_get_handler_v2.*)$|/\* WARNING: raptor_uri_get_handler_v2 - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_uri_set_handler.*)$|/\* WARNING: raptor_uri_set_handler - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_uri_set_handler_v2.*)$|/\* WARNING: raptor_uri_set_handler_v2 - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_www_finish.*)$|/\* WARNING: raptor_www_finish - deleted. No need for this to be public. \*/ $1|g;
s|^(.*raptor_www_finish_v2.*)$|/\* WARNING: raptor_www_finish_v2 - deleted. No need for this to be public. \*/ $1|g;
s|^(.*raptor_www_init.*)$|/\* WARNING: raptor_www_init - deleted. No need for this to be public. \*/ $1|g;
s|^(.*raptor_www_init_v2.*)$|/\* WARNING: raptor_www_init_v2 - deleted. No need for this to be public. \*/ $1|g;
s|^(.*raptor_www_no_www_library_init_finish.*)$|/\* WARNING: raptor_www_no_www_library_init_finish - deleted. Deprecated for raptor_world_set_flag(). \*/ $1|g;
s|^(.*raptor_www_no_www_library_init_finish_v2.*)$|/\* WARNING: raptor_www_no_www_library_init_finish_v2 - deleted. Deprecated for raptor_world_set_flag(). \*/ $1|g;
s|^(.*raptor_www_set_error_handler.*)$|/\* WARNING: raptor_www_set_error_handler - deleted. Replaced by raptor_world_set_log_handler() on the #raptor_world object. \*/ $1|g;

# Deleted types
s|^(.*raptor_error_handlers.*)$|/\* WARNING: raptor_error_handlers - deleted. Replaced by generic raptor log mechanism.  See raptor_world_set_log_handler() \*/ $1|g;
s|^(.*raptor_free_uri_func.*)$|/\* WARNING: raptor_free_uri_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_libxml_flags.*)$|/\* WARNING: raptor_libxml_flags - deleted. replaced by raptor_world_set_flags() with #raptor_world_flag \*/ $1|g;
s|^(.*raptor_message_handler.*)$|/\* WARNING: raptor_message_handler - deleted. Replaced by generic raptor log mechanism.  See raptor_world_set_log_handler() \*/ $1|g;
s|^(.*raptor_message_handler_closure.*)$|/\* WARNING: raptor_message_handler_closure - deleted. Replaced by generic raptor log mechanism.  See raptor_world_set_log_handler() \*/ $1|g;
s|^(.*raptor_new_uri_for_rdf_concept_func.*)$|/\* WARNING: raptor_new_uri_for_rdf_concept_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_new_uri_from_uri_local_name_func.*)$|/\* WARNING: raptor_new_uri_from_uri_local_name_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_new_uri_func.*)$|/\* WARNING: raptor_new_uri_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_new_uri_relative_to_base_func.*)$|/\* WARNING: raptor_new_uri_relative_to_base_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_ntriples_parser.*)$|/\* WARNING: raptor_ntriples_parser - deleted. replaced by #raptor_parser \*/ $1|g;
s|^(.*raptor_ntriples_term_type.*)$|/\* WARNING: raptor_ntriples_term_type - deleted. replaced by #raptor_term_type \*/ $1|g;
s|^(.*raptor_uri_as_counted_string_func.*)$|/\* WARNING: raptor_uri_as_counted_string_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_uri_as_string_func.*)$|/\* WARNING: raptor_uri_as_string_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_uri_compare_func.*)$|/\* WARNING: raptor_uri_compare_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_uri_copy_func.*)$|/\* WARNING: raptor_uri_copy_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_uri_equals_func.*)$|/\* WARNING: raptor_uri_equals_func - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_uri_handler.*)$|/\* WARNING: raptor_uri_handler - deleted. Entire URI implementation is internal and not replaceable. \*/ $1|g;
s|^(.*raptor_uri_source.*)$|/\* WARNING: raptor_uri_source - deleted. URI source was useless. \*/ $1|g;

# Deleted enums
s|^(.*RAPTOR_IDENTIFIER_TYPE_ORDINAL.*)$|/\* WARNING: RAPTOR_IDENTIFIER_TYPE_ORDINAL - deleted. Deprecated value deleted. \*/ $1|g;
s|^(.*RAPTOR_URI_SOURCE_UNKNOWN.*)$|/\* WARNING: RAPTOR_URI_SOURCE_UNKNOWN - deleted. URI source concept removed. \*/ $1|g;
s|^(.*RAPTOR_URI_SOURCE_NOT_URI.*)$|/\* WARNING: RAPTOR_URI_SOURCE_NOT_URI - deleted. URI source concept removed. \*/ $1|g;
s|^(.*RAPTOR_URI_SOURCE_ELEMENT.*)$|/\* WARNING: RAPTOR_URI_SOURCE_ELEMENT - deleted. URI source concept removed. \*/ $1|g;
s|^(.*RAPTOR_URI_SOURCE_ATTRIBUTE.*)$|/\* WARNING: RAPTOR_URI_SOURCE_ATTRIBUTE - deleted. URI source concept removed. \*/ $1|g;
s|^(.*RAPTOR_URI_SOURCE_ID.*)$|/\* WARNING: RAPTOR_URI_SOURCE_ID - deleted. URI source concept removed. \*/ $1|g;
s|^(.*RAPTOR_URI_SOURCE_URI.*)$|/\* WARNING: RAPTOR_URI_SOURCE_URI - deleted. URI source concept removed. \*/ $1|g;
s|^(.*RAPTOR_URI_SOURCE_GENERATED.*)$|/\* WARNING: RAPTOR_URI_SOURCE_GENERATED - deleted. URI source concept removed. \*/ $1|g;
s|^(.*RAPTOR_URI_SOURCE_BLANK_ID.*)$|/\* WARNING: RAPTOR_URI_SOURCE_BLANK_ID - deleted. URI source concept removed. \*/ $1|g;
s|^(.*RAPTOR_FEATURE_ASSUME_IS_RDF.*)$|/\* WARNING: RAPTOR_FEATURE_ASSUME_IS_RDF - deleted. Never used. \*/ $1|g;
s|^(.*RAPTOR_FEATURE_START_URI.*)$|/\* WARNING: RAPTOR_FEATURE_START_URI - deleted. Never used. \*/ $1|g;
s|^(.*RAPTOR_GENID_TYPE_BNODEID.*)$|/\* WARNING: RAPTOR_GENID_TYPE_BNODEID - deleted. There is just one type of generated ID now. \*/ $1|g;
s|^(.*RAPTOR_GENID_TYPE_BAGID.*)$|/\* WARNING: RAPTOR_GENID_TYPE_BAGID - deleted. There is just one type of generated ID now. \*/ $1|g;

# Renamed functions
s|raptor_format_locator\(|raptor_locator_format\(|g;
s|raptor_get_feature_count\(|raptor_option_get_count\(|g;
s|raptor_get_locator\(|raptor_parser_get_locator\(|g;
s|raptor_get_name\(|raptor_parser_get_name\(|g;
s|raptor_guess_parser_name_v2\(|raptor_world_guess_parser_name\(|g;
s|raptor_namespace_copy\(|raptor_namespace_stack_start_namespace\(|g;
s|raptor_namespaces_format\(|raptor_namespace_format_as_xml\(|g;
s|raptor_namespaces_qname_from_uri\(|raptor_new_qname_from_namespace_uri\(|g;
s|raptor_new_namespace_parts_from_string\(|raptor_xml_namespace_string_parse\(|g;
s|raptor_new_parser_for_content_v2\(|raptor_new_parser_for_content\(|g;
s|raptor_new_parser_v2\(|raptor_new_parser\(|g;
s|raptor_new_qname_from_namespace_local_name_v2\(|raptor_new_qname_from_namespace_local_name\(|g;
s|raptor_new_serializer_v2\(|raptor_new_serializer\(|g;
s|raptor_new_uri_from_id_v2\(|raptor_new_uri_from_id\(|g;
s|raptor_new_uri_from_uri_local_name_v2\(|raptor_new_uri_from_uri_local_name\(|g;
s|raptor_new_uri_relative_to_base_v2\(|raptor_new_uri_relative_to_base\(|g;
s|raptor_new_uri_v2\(|raptor_new_uri\(|g;
s|raptor_parse_abort\(|raptor_parser_parse_abort\(|g;
s|raptor_parse_chunk\(|raptor_parser_parse_chunk\(|g;
s|raptor_parse_file\(|raptor_parser_parse_file\(|g;
s|raptor_parse_file_stream\(|raptor_parser_parse_file_stream\(|g;
s|raptor_parse_uri\(|raptor_parser_parse_uri\(|g;
s|raptor_parse_uri_with_connection\(|raptor_parser_parse_uri_with_connection\(|g;
s|raptor_serialize_end\(|raptor_serializer_serialize_end\(|g;
s|raptor_serialize_set_namespace\(|raptor_serializer_set_namespace\(|g;
s|raptor_serialize_set_namespace_from_namespace\(|raptor_serializer_set_namespace_from_namespace\(|g;
s|raptor_serialize_start\(|raptor_serializer_start_to_iostream\(|g;
s|raptor_serialize_start_to_file_handle\(|raptor_serializer_start_to_file_handle\(|g;
s|raptor_serialize_start_to_filename\(|raptor_serializer_start_to_filename\(|g;
s|raptor_serialize_start_to_iostream\(|raptor_serializer_start_to_iostream\(|g;
s|raptor_serialize_start_to_string\(|raptor_serializer_start_to_string\(|g;
s|raptor_serializer_syntax_name_check_v2\(|raptor_world_is_serializer_name\(|g;
s|raptor_set_namespace_handler\(|raptor_parser_set_namespace_handler\(|g;
s|raptor_set_statement_handler\(|raptor_parser_set_statement_handler\(|g;
s|raptor_start_parse\(|raptor_parser_parse_start\(|g;
s|raptor_uri_is_file_uri\(|raptor_uri_uri_string_is_file_uri\(|g;
s|raptor_utf8_check\(|raptor_unicode_check_utf8_string\(|g;
s|raptor_www_free\(|raptor_free_www\(|g;
s|raptor_www_new_v2\(|raptor_new_www\(|g;
s|raptor_www_new_with_connection_v2\(|raptor_new_www_with_connection\(|g;

# Renamed enums
s|RAPTOR_IDENTIFIER_TYPE_UNKNOWN|RAPTOR_TERM_TYPE_UNKNOWN|g;
s|RAPTOR_IDENTIFIER_TYPE_RESOURCE|RAPTOR_TERM_TYPE_URI|g;
s|RAPTOR_IDENTIFIER_TYPE_ANONYMOUS|RAPTOR_TERM_TYPE_BLANK|g;
s|RAPTOR_IDENTIFIER_TYPE_PREDICATE|RAPTOR_TERM_TYPE_URI|g;
s|RAPTOR_IDENTIFIER_TYPE_LITERAL|RAPTOR_TERM_TYPE_LITERAL|g;
s|RAPTOR_IDENTIFIER_TYPE_XML_LITERAL|RAPTOR_TERM_TYPE_LITERAL|g;
s|RAPTOR_NTRIPLES_TERM_TYPE_URI_REF|RAPTOR_TERM_TYPE_URI|g;
s|RAPTOR_NTRIPLES_TERM_TYPE_BLANK_NODE|RAPTOR_TERM_TYPE_BLANK|g;
s|RAPTOR_NTRIPLES_TERM_TYPE_LITERAL|RAPTOR_TERM_TYPE_LITERAL|g;
s|RAPTOR_FEATURE_SCANNING |RAPTOR_OPTION_SCANNING|g;
s|RAPTOR_FEATURE_ALLOW_NON_NS_ATTRIBUTES|RAPTOR_OPTION_ALLOW_NON_NS_ATTRIBUTES|g;
s|RAPTOR_FEATURE_ALLOW_OTHER_PARSETYPES|RAPTOR_OPTION_ALLOW_OTHER_PARSETYPES|g;
s|RAPTOR_FEATURE_ALLOW_BAGID|RAPTOR_OPTION_ALLOW_BAGID|g;
s|RAPTOR_FEATURE_ALLOW_RDF_TYPE_RDF_LIST|RAPTOR_OPTION_ALLOW_RDF_TYPE_RDF_LIST|g;
s|RAPTOR_FEATURE_NORMALIZE_LANGUAGE|RAPTOR_OPTION_NORMALIZE_LANGUAGE|g;
s|RAPTOR_FEATURE_NON_NFC_FATAL|RAPTOR_OPTION_NON_NFC_FATAL|g;
s|RAPTOR_FEATURE_WARN_OTHER_PARSETYPES|RAPTOR_OPTION_WARN_OTHER_PARSETYPES|g;
s|RAPTOR_FEATURE_CHECK_RDF_ID|RAPTOR_OPTION_CHECK_RDF_ID|g;
s|RAPTOR_FEATURE_RELATIVE_URIS|RAPTOR_OPTION_RELATIVE_URIS|g;
s|RAPTOR_FEATURE_WRITER_AUTO_INDENT|RAPTOR_OPTION_WRITER_AUTO_INDENT|g;
s|RAPTOR_FEATURE_WRITER_AUTO_EMPTY|RAPTOR_OPTION_WRITER_AUTO_EMPTY|g;
s|RAPTOR_FEATURE_WRITER_INDENT_WIDTH|RAPTOR_OPTION_WRITER_INDENT_WIDTH|g;
s|RAPTOR_FEATURE_WRITER_XML_VERSION|RAPTOR_OPTION_WRITER_XML_VERSION|g;
s|RAPTOR_FEATURE_WRITER_XML_DECLARATION|RAPTOR_OPTION_WRITER_XML_DECLARATION|g;
s|RAPTOR_FEATURE_NO_NET|RAPTOR_OPTION_NO_NET|g;
s|RAPTOR_FEATURE_RESOURCE_BORDER|RAPTOR_OPTION_RESOURCE_BORDER|g;
s|RAPTOR_FEATURE_LITERAL_BORDER|RAPTOR_OPTION_LITERAL_BORDER|g;
s|RAPTOR_FEATURE_BNODE_BORDER|RAPTOR_OPTION_BNODE_BORDER|g;
s|RAPTOR_FEATURE_RESOURCE_FILL|RAPTOR_OPTION_RESOURCE_FILL|g;
s|RAPTOR_FEATURE_LITERAL_FILL|RAPTOR_OPTION_LITERAL_FILL|g;
s|RAPTOR_FEATURE_BNODE_FILL|RAPTOR_OPTION_BNODE_FILL|g;
s|RAPTOR_FEATURE_HTML_TAG_SOUP|RAPTOR_OPTION_HTML_TAG_SOUP|g;
s|RAPTOR_FEATURE_MICROFORMATS|RAPTOR_OPTION_MICROFORMATS|g;
s|RAPTOR_FEATURE_HTML_LINK|RAPTOR_OPTION_HTML_LINK|g;
s|RAPTOR_FEATURE_WWW_TIMEOUT|RAPTOR_OPTION_WWW_TIMEOUT|g;
s|RAPTOR_FEATURE_WRITE_BASE_URI|RAPTOR_OPTION_WRITE_BASE_URI|g;
s|RAPTOR_FEATURE_WWW_HTTP_CACHE_CONTROL|RAPTOR_OPTION_WWW_HTTP_CACHE_CONTROL|g;
s|RAPTOR_FEATURE_WWW_HTTP_USER_AGENT|RAPTOR_OPTION_WWW_HTTP_USER_AGENT|g;
s|RAPTOR_FEATURE_JSON_CALLBACK|RAPTOR_OPTION_JSON_CALLBACK|g;
s|RAPTOR_FEATURE_JSON_EXTRA_DATA|RAPTOR_OPTION_JSON_EXTRA_DATA|g;
s|RAPTOR_FEATURE_RSS_TRIPLES|RAPTOR_OPTION_RSS_TRIPLES|g;
s|RAPTOR_FEATURE_ATOM_ENTRY_URI|RAPTOR_OPTION_ATOM_ENTRY_URI|g;
s|RAPTOR_FEATURE_PREFIX_ELEMENTS|RAPTOR_OPTION_PREFIX_ELEMENTS|g;
s|RAPTOR_FEATURE_LAST|RAPTOR_OPTION_LAST|g;
s|RAPTOR_LOG_LEVEL_WARNING|RAPTOR_LOG_LEVEL_WARN|g;
s|RAPTOR_LIBXML_FLAGS_GENERIC_ERROR_SAVE|RAPTOR_WORLD_FLAG_LIBXML_GENERIC_ERROR_SAVE|g;
s|RAPTOR_LIBXML_FLAGS_STRUCTURED_ERROR_SAVE|RAPTOR_WORLD_FLAG_LIBXML_STRUCTURED_ERROR_SAVE|g;

# Changed functions
s|^(.*)(raptor_feature_from_uri)(.*)$|/\* WARNING: raptor_feature_from_uri.  \*/ ${1}raptor_world_get_option_from_uri${3}|g;
s|^(.*)(raptor_feature_from_uri_v2)(.*)$|/\* WARNING: raptor_feature_from_uri_v2.  \*/ ${1}raptor_world_get_option_from_uri${3}|g;
s|^(.*)(raptor_features_enumerate)(.*)$|/\* WARNING: raptor_features_enumerate. Call with domain = RAPTOR_DOMAIN_PARSER \*/ ${1}raptor_world_get_option_description${3}|g;
s|^(.*)(raptor_features_enumerate_v2)(.*)$|/\* WARNING: raptor_features_enumerate_v2. Call with domain = RAPTOR_DOMAIN_PARSER \*/ ${1}raptor_world_get_option_description${3}|g;
s|^(.*)(raptor_format_locator_v2)(.*)$|/\* WARNING: raptor_format_locator_v2.  \*/ ${1}raptor_locator_format${3}|g;
s|^(.*)(raptor_free_uri_v2)(.*)$|/\* WARNING: raptor_free_uri_v2.  \*/ ${1}raptor_free_uri${3}|g;
s|^(.*)(raptor_get_feature)(.*)$|/\* WARNING: raptor_get_feature.  \*/ ${1}raptor_parser_get_option${3}|g;
s|^(.*)(raptor_get_label)(.*)$|/\* WARNING: raptor_get_label. Use label field of returned description. \*/ ${1}raptor_parser_get_description${3}|g;
s|^(.*)(raptor_get_mime_type)(.*)$|/\* WARNING: raptor_get_mime_type. Use the mime_types array field of returned #raptor_syntax_description \*/ ${1}raptor_parser_get_description${3}|g;
s|^(.*)(raptor_get_need_base_uri)(.*)$|/\* WARNING: raptor_get_need_base_uri. Use the #RAPTOR_SYNTAX_NEED_BASE_URI bitflag in the flags field of the returned #raptor_syntax_description \*/ ${1}raptor_parser_get_description${3}|g;
s|^(.*)(raptor_guess_parser_name)(.*)$|/\* WARNING: raptor_guess_parser_name.  \*/ ${1}raptor_world_guess_parser_name${3}|g;
s|^(.*)(raptor_iostream_format_hexadecimal)(.*)$|/\* WARNING: raptor_iostream_format_hexadecimal.  \*/ ${1}raptor_iostream_hexadecimal_write${3}|g;
s|^(.*)(raptor_iostream_read_bytes)(.*)$|/\* WARNING: raptor_iostream_read_bytes.  \*/ ${1}raptor_iostream_read_bytes${3}|g;
s|^(.*)(raptor_iostream_write_byte)(.*)$|/\* WARNING: raptor_iostream_write_byte.  \*/ ${1}raptor_iostream_write_byte${3}|g;
s|^(.*)(raptor_iostream_write_bytes)(.*)$|/\* WARNING: raptor_iostream_write_bytes.  \*/ ${1}raptor_iostream_write_bytes${3}|g;
s|^(.*)(raptor_iostream_write_counted_string)(.*)$|/\* WARNING: raptor_iostream_write_counted_string.  \*/ ${1}raptor_iostream_counted_string_write${3}|g;
s|^(.*)(raptor_iostream_write_decimal)(.*)$|/\* WARNING: raptor_iostream_write_decimal.  \*/ ${1}raptor_iostream_decimal_write${3}|g;
s|^(.*)(raptor_iostream_write_end)(.*)$|/\* WARNING: raptor_iostream_write_end.  \*/ ${1}raptor_iostream_write_end${3}|g;
s|^(.*)(raptor_iostream_write_namespace)(.*)$|/\* WARNING: raptor_iostream_write_namespace.  \*/ ${1}raptor_namespace_write${3}|g;
s|^(.*)(raptor_iostream_write_qname)(.*)$|/\* WARNING: raptor_iostream_write_qname.  \*/ ${1}raptor_qname_write${3}|g;
s|^(.*)(raptor_iostream_write_statement_ntriples)(.*)$|/\* WARNING: raptor_iostream_write_statement_ntriples. Gains extra flag arg to decide whether to write any graph term. \*/ ${1}raptor_statement_ntriples_write${3}|g;
s|^(.*)(raptor_iostream_write_string)(.*)$|/\* WARNING: raptor_iostream_write_string.  \*/ ${1}raptor_iostream_string_write${3}|g;
s|^(.*)(raptor_iostream_write_string_ntriples)(.*)$|/\* WARNING: raptor_iostream_write_string_ntriples.  \*/ ${1}raptor_string_ntriples_write${3}|g;
s|^(.*)(raptor_iostream_write_string_python)(.*)$|/\* WARNING: raptor_iostream_write_string_python.  \*/ ${1}raptor_string_python_write${3}|g;
s|^(.*)(raptor_iostream_write_stringbuffer)(.*)$|/\* WARNING: raptor_iostream_write_stringbuffer.  \*/ ${1}raptor_stringbuffer_write${3}|g;
s|^(.*)(raptor_iostream_write_uri)(.*)$|/\* WARNING: raptor_iostream_write_uri.  \*/ ${1}raptor_uri_write${3}|g;
s|^(.*)(raptor_iostream_write_uri_v2)(.*)$|/\* WARNING: raptor_iostream_write_uri_v2.  \*/ ${1}raptor_uri_write${3}|g;
s|^(.*)(raptor_iostream_write_xml_any_escaped_string)(.*)$|/\* WARNING: raptor_iostream_write_xml_any_escaped_string.  \*/ ${1}raptor_xml_escape_string_any_write${3}|g;
s|^(.*)(raptor_iostream_write_xml_element)(.*)$|/\* WARNING: raptor_iostream_write_xml_element.  \*/ ${1}raptor_xml_element_write${3}|g;
s|^(.*)(raptor_iostream_write_xml_escaped_string)(.*)$|/\* WARNING: raptor_iostream_write_xml_escaped_string.  \*/ ${1}raptor_xml_escape_string_write${3}|g;
s|^(.*)(raptor_locator_uri_v2)(.*)$|/\* WARNING: raptor_locator_uri_v2.  \*/ ${1}raptor_locator_uri${3}|g;
s|^(.*)(raptor_namespaces_init)(.*)$|/\* WARNING: raptor_namespaces_init.  \*/ ${1}raptor_namespaces_init${3}|g;
s|^(.*)(raptor_namespaces_init_v2)(.*)$|/\* WARNING: raptor_namespaces_init_v2.  \*/ ${1}raptor_namespaces_init${3}|g;
s|^(.*)(raptor_new_iostream_from_file_handle)(.*)$|/\* WARNING: raptor_new_iostream_from_file_handle.  \*/ ${1}raptor_new_iostream_from_file_handle${3}|g;
s|^(.*)(raptor_new_iostream_from_filename)(.*)$|/\* WARNING: raptor_new_iostream_from_filename.  \*/ ${1}raptor_new_iostream_from_filename${3}|g;
s|^(.*)(raptor_new_iostream_from_handler)(.*)$|/\* WARNING: raptor_new_iostream_from_handler.  \*/ ${1}raptor_new_iostream_from_handler${3}|g;
s|^(.*)(raptor_new_iostream_from_handler2)(.*)$|/\* WARNING: raptor_new_iostream_from_handler2.  \*/ ${1}raptor_new_iostream_from_handler${3}|g;
s|^(.*)(raptor_new_iostream_from_sink)(.*)$|/\* WARNING: raptor_new_iostream_from_sink.  \*/ ${1}raptor_new_iostream_from_sink${3}|g;
s|^(.*)(raptor_new_iostream_from_string)(.*)$|/\* WARNING: raptor_new_iostream_from_string.  \*/ ${1}raptor_new_iostream_from_string${3}|g;
s|^(.*)(raptor_new_iostream_to_file_handle)(.*)$|/\* WARNING: raptor_new_iostream_to_file_handle.  \*/ ${1}raptor_new_iostream_to_file_handle${3}|g;
s|^(.*)(raptor_new_iostream_to_filename)(.*)$|/\* WARNING: raptor_new_iostream_to_filename.  \*/ ${1}raptor_new_iostream_to_filename${3}|g;
s|^(.*)(raptor_new_iostream_to_sink)(.*)$|/\* WARNING: raptor_new_iostream_to_sink.  \*/ ${1}raptor_new_iostream_to_sink${3}|g;
s|^(.*)(raptor_new_iostream_to_string)(.*)$|/\* WARNING: raptor_new_iostream_to_string.  \*/ ${1}raptor_new_iostream_to_string${3}|g;
s|^(.*)(raptor_new_namespaces)(.*)$|/\* WARNING: raptor_new_namespaces.  \*/ ${1}raptor_new_namespaces${3}|g;
s|^(.*)(raptor_new_namespaces_v2)(.*)$|/\* WARNING: raptor_new_namespaces_v2.  \*/ ${1}raptor_new_namespaces${3}|g;
s|^(.*)(raptor_new_parser)(.*)$|/\* WARNING: raptor_new_parser.  \*/ ${1}raptor_new_parser${3}|g;
s|^(.*)(raptor_new_parser_for_content)(.*)$|/\* WARNING: raptor_new_parser_for_content.  \*/ ${1}raptor_new_parser_for_content${3}|g;
s|^(.*)(raptor_new_qname)(.*)$|/\* WARNING: raptor_new_qname.  \*/ ${1}raptor_new_qname${3}|g;
s|^(.*)(raptor_new_qname_from_namespace_local_name)(.*)$|/\* WARNING: raptor_new_qname_from_namespace_local_name.  \*/ ${1}raptor_new_qname_from_namespace_local_name${3}|g;
s|^(.*)(raptor_new_sax2)(.*)$|/\* WARNING: raptor_new_sax2.  \*/ ${1}raptor_new_sax2${3}|g;
s|^(.*)(raptor_new_sequence)(.*)$|/\* WARNING: raptor_new_sequence.  \*/ ${1}raptor_new_sequence${3}|g;
s|^(.*)(raptor_new_sequence_v2)(.*)$|/\* WARNING: raptor_new_sequence_v2.  \*/ ${1}raptor_new_sequence${3}|g;
s|^(.*)(raptor_new_serializer)(.*)$|/\* WARNING: raptor_new_serializer.  \*/ ${1}raptor_new_serializer${3}|g;
s|^(.*)(raptor_new_uri)(.*)$|/\* WARNING: raptor_new_uri.  \*/ ${1}raptor_new_uri${3}|g;
s|^(.*)(raptor_new_uri_for_rdf_concept)(.*)$|/\* WARNING: raptor_new_uri_for_rdf_concept.  \*/ ${1}raptor_new_uri_for_rdf_concept${3}|g;
s|^(.*)(raptor_new_uri_for_rdf_concept_v2)(.*)$|/\* WARNING: raptor_new_uri_for_rdf_concept_v2.  \*/ ${1}raptor_new_uri_for_rdf_concept${3}|g;
s|^(.*)(raptor_new_uri_for_retrieval_v2)(.*)$|/\* WARNING: raptor_new_uri_for_retrieval_v2.  \*/ ${1}raptor_new_uri_for_retrieval${3}|g;
s|^(.*)(raptor_new_uri_for_xmlbase_v2)(.*)$|/\* WARNING: raptor_new_uri_for_xmlbase_v2.  \*/ ${1}raptor_new_uri_for_xmlbase${3}|g;
s|^(.*)(raptor_new_uri_from_id)(.*)$|/\* WARNING: raptor_new_uri_from_id.  \*/ ${1}raptor_new_uri_from_id${3}|g;
s|^(.*)(raptor_new_uri_from_uri_local_name)(.*)$|/\* WARNING: raptor_new_uri_from_uri_local_name.  \*/ ${1}raptor_new_uri_from_uri_local_name${3}|g;
s|^(.*)(raptor_new_uri_relative_to_base)(.*)$|/\* WARNING: raptor_new_uri_relative_to_base.  \*/ ${1}raptor_new_uri_relative_to_base${3}|g;
s|^(.*)(raptor_new_xml_writer)(.*)$|/\* WARNING: raptor_new_xml_writer.  \*/ ${1}raptor_new_xml_writer${3}|g;
s|^(.*)(raptor_new_xml_writer_v2)(.*)$|/\* WARNING: raptor_new_xml_writer_v2.  \*/ ${1}raptor_new_xml_writer${3}|g;
s|^(.*)(raptor_parser_get_feature_string)(.*)$|/\* WARNING: raptor_parser_get_feature_string.  \*/ ${1}raptor_parser_get_option${3}|g;
s|^(.*)(raptor_parser_set_feature_string)(.*)$|/\* WARNING: raptor_parser_set_feature_string.  \*/ ${1}raptor_parser_set_option${3}|g;
s|^(.*)(raptor_parsers_enumerate)(.*)$|/\* WARNING: raptor_parsers_enumerate.  \*/ ${1}raptor_world_get_parser_description${3}|g;
s|^(.*)(raptor_parsers_enumerate_v2)(.*)$|/\* WARNING: raptor_parsers_enumerate_v2.  \*/ ${1}raptor_world_get_parser_description${3}|g;
s|^(.*)(raptor_print_locator)(.*)$|/\* WARNING: raptor_print_locator.  \*/ ${1}raptor_locator_print${3}|g;
s|^(.*)(raptor_print_locator_v2)(.*)$|/\* WARNING: raptor_print_locator_v2.  \*/ ${1}raptor_locator_print${3}|g;
s|^(.*)(raptor_print_statement)(.*)$|/\* WARNING: raptor_print_statement.  \*/ ${1}raptor_statement_print${3}|g;
s|^(.*)(raptor_print_statement_as_ntriples)(.*)$|/\* WARNING: raptor_print_statement_as_ntriples.  \*/ ${1}raptor_statement_print_as_ntriples${3}|g;
s|^(.*)(raptor_print_statement_as_ntriples_v2)(.*)$|/\* WARNING: raptor_print_statement_as_ntriples_v2.  \*/ ${1}raptor_statement_print_as_ntriples${3}|g;
s|^(.*)(raptor_print_statement_v2)(.*)$|/\* WARNING: raptor_print_statement_v2.  \*/ ${1}raptor_statement_print${3}|g;
s|^(.*)(raptor_qname_string_to_uri)(.*)$|/\* WARNING: raptor_qname_string_to_uri.  \*/ ${1}raptor_qname_string_to_uri${3}|g;
s|^(.*)(raptor_sequence_print)(.*)$|/\* WARNING: raptor_sequence_print.  \*/ ${1}raptor_sequence_print${3}|g;
s|^(.*)(raptor_sequence_sort)(.*)$|/\* WARNING: raptor_sequence_sort.  \*/ ${1}raptor_sequence_sort${3}|g;
s|^(.*)(raptor_serialize_statement)(.*)$|/\* WARNING: raptor_serialize_statement.  \*/ ${1}raptor_serializer_serialize_statement${3}|g;
s|^(.*)(raptor_serializer_features_enumerate)(.*)$|/\* WARNING: raptor_serializer_features_enumerate. Call with domain = RAPTOR_DOMAIN_SERIALIZER \*/ ${1}raptor_world_get_option_description${3}|g;
s|^(.*)(raptor_serializer_features_enumerate_v2)(.*)$|/\* WARNING: raptor_serializer_features_enumerate_v2. Call with domain = RAPTOR_DOMAIN_SERIALIZER \*/ ${1}raptor_world_get_option_description${3}|g;
s|^(.*)(raptor_serializer_get_feature)(.*)$|/\* WARNING: raptor_serializer_get_feature.  \*/ ${1}raptor_serializer_get_option${3}|g;
s|^(.*)(raptor_serializer_get_feature_string)(.*)$|/\* WARNING: raptor_serializer_get_feature_string.  \*/ ${1}raptor_serializer_get_option${3}|g;
s|^(.*)(raptor_serializer_set_feature)(.*)$|/\* WARNING: raptor_serializer_set_feature.  \*/ ${1}raptor_serializer_set_option${3}|g;
s|^(.*)(raptor_serializer_set_feature_string)(.*)$|/\* WARNING: raptor_serializer_set_feature_string.  \*/ ${1}raptor_serializer_set_option${3}|g;
s|^(.*)(raptor_serializer_syntax_name_check)(.*)$|/\* WARNING: raptor_serializer_syntax_name_check.  \*/ ${1}raptor_world_is_serializer_name${3}|g;
s|^(.*)(raptor_serializers_enumerate)(.*)$|/\* WARNING: raptor_serializers_enumerate.  \*/ ${1}raptor_world_get_serializer_description${3}|g;
s|^(.*)(raptor_serializers_enumerate_v2)(.*)$|/\* WARNING: raptor_serializers_enumerate_v2.  \*/ ${1}raptor_world_get_serializer_description${3}|g;
s|^(.*)(raptor_set_default_generate_id_parameters)(.*)$|/\* WARNING: raptor_set_default_generate_id_parameters.  \*/ ${1}raptor_world_set_generate_bnodeid_parameters${3}|g;
s|^(.*)(raptor_set_feature)(.*)$|/\* WARNING: raptor_set_feature.  \*/ ${1}raptor_parser_set_option${3}|g;
s|^(.*)(raptor_set_generate_id_handler)(.*)$|/\* WARNING: raptor_set_generate_id_handler.  \*/ ${1}raptor_world_set_generate_bnodeid_handler${3}|g;
s|^(.*)(raptor_set_graph_handler)(.*)$|/\* WARNING: raptor_set_graph_handler.  \*/ ${1}raptor_parser_set_graph_mark_handler${3}|g;
s|^(.*)(raptor_set_libxslt_security_preferences)(.*)$|/\* WARNING: raptor_set_libxslt_security_preferences.  \*/ ${1}raptor_world_set_libxslt_security_preferences${3}|g;
s|^(.*)(raptor_statement_compare_v2)(.*)$|/\* WARNING: raptor_statement_compare_v2.  \*/ ${1}raptor_statement_compare${3}|g;
s|^(.*)(raptor_syntax_name_check)(.*)$|/\* WARNING: raptor_syntax_name_check.  \*/ ${1}raptor_world_is_parser_name${3}|g;
s|^(.*)(raptor_syntax_name_check_v2)(.*)$|/\* WARNING: raptor_syntax_name_check_v2.  \*/ ${1}raptor_world_is_parser_name${3}|g;
s|^(.*)(raptor_syntaxes_enumerate)(.*)$|/\* WARNING: raptor_syntaxes_enumerate.  \*/ ${1}raptor_world_get_parser_description${3}|g;
s|^(.*)(raptor_syntaxes_enumerate_v2)(.*)$|/\* WARNING: raptor_syntaxes_enumerate_v2.  \*/ ${1}raptor_world_get_parser_description${3}|g;
s|^(.*)(raptor_unicode_char_to_utf8)(.*)$|/\* WARNING: raptor_unicode_char_to_utf8.  \*/ ${1}raptor_unicode_utf8_string_put_char${3}|g;
s|^(.*)(raptor_uri_as_counted_string_v2)(.*)$|/\* WARNING: raptor_uri_as_counted_string_v2.  \*/ ${1}raptor_uri_as_counted_string${3}|g;
s|^(.*)(raptor_uri_as_string_v2)(.*)$|/\* WARNING: raptor_uri_as_string_v2.  \*/ ${1}raptor_uri_as_string${3}|g;
s|^(.*)(raptor_uri_compare_v2)(.*)$|/\* WARNING: raptor_uri_compare_v2.  \*/ ${1}raptor_uri_compare${3}|g;
s|^(.*)(raptor_uri_copy_v2)(.*)$|/\* WARNING: raptor_uri_copy_v2.  \*/ ${1}raptor_uri_copy${3}|g;
s|^(.*)(raptor_uri_equals_v2)(.*)$|/\* WARNING: raptor_uri_equals_v2.  \*/ ${1}raptor_uri_equals${3}|g;
s|^(.*)(raptor_uri_print)(.*)$|/\* WARNING: raptor_uri_print.  \*/ ${1}raptor_uri_print${3}|g;
s|^(.*)(raptor_uri_print_v2)(.*)$|/\* WARNING: raptor_uri_print_v2.  \*/ ${1}raptor_uri_print${3}|g;
s|^(.*)(raptor_uri_resolve_uri_reference)(.*)$|/\* WARNING: raptor_uri_resolve_uri_reference.  \*/ ${1}raptor_uri_resolve_uri_reference${3}|g;
s|^(.*)(raptor_uri_to_counted_string_v2)(.*)$|/\* WARNING: raptor_uri_to_counted_string_v2.  \*/ ${1}raptor_uri_to_counted_string${3}|g;
s|^(.*)(raptor_uri_to_relative_counted_uri_string_v2)(.*)$|/\* WARNING: raptor_uri_to_relative_counted_uri_string_v2.  \*/ ${1}raptor_uri_to_relative_counted_uri_string${3}|g;
s|^(.*)(raptor_uri_to_relative_uri_string_v2)(.*)$|/\* WARNING: raptor_uri_to_relative_uri_string_v2.  \*/ ${1}raptor_uri_to_relative_uri_string${3}|g;
s|^(.*)(raptor_uri_to_string_v2)(.*)$|/\* WARNING: raptor_uri_to_string_v2.  \*/ ${1}raptor_uri_to_string${3}|g;
s|^(.*)(raptor_utf8_to_unicode_char)(.*)$|/\* WARNING: raptor_utf8_to_unicode_char.  \*/ ${1}raptor_unicode_utf8_string_get_char${3}|g;
s|^(.*)(raptor_world_set_libxml_flags)(.*)$|/\* WARNING: raptor_world_set_libxml_flags.  \*/ ${1}raptor_world_set_flag${3}|g;
s|^(.*)(raptor_world_set_libxslt_security_preferences)(.*)$|/\* WARNING: raptor_world_set_libxslt_security_preferences.  \*/ ${1}raptor_world_set_libxslt_security_preferences${3}|g;
s|^(.*)(raptor_www_fetch_to_string)(.*)$|/\* WARNING: raptor_www_fetch_to_string.  \*/ ${1}raptor_www_fetch_to_string${3}|g;
s|^(.*)(raptor_www_new)(.*)$|/\* WARNING: raptor_www_new.  \*/ ${1}raptor_new_www${3}|g;
s|^(.*)(raptor_www_new_with_connection)(.*)$|/\* WARNING: raptor_www_new_with_connection.  \*/ ${1}raptor_new_www_with_connection${3}|g;
s|^(.*)(raptor_xml_any_escape_string)(.*)$|/\* WARNING: raptor_xml_any_escape_string.  \*/ ${1}raptor_xml_escape_string_any${3}|g;
s|^(.*)(raptor_xml_escape_string)(.*)$|/\* WARNING: raptor_xml_escape_string.  \*/ ${1}raptor_xml_escape_string${3}|g;
s|^(.*)(raptor_xml_writer_features_enumerate)(.*)$|/\* WARNING: raptor_xml_writer_features_enumerate. Call with domain = RAPTOR_DOMAIN_XML_WRITER \*/ ${1}raptor_world_get_option_description${3}|g;
s|^(.*)(raptor_xml_writer_features_enumerate_v2)(.*)$|/\* WARNING: raptor_xml_writer_features_enumerate_v2. Call with domain = RAPTOR_DOMAIN_XML_WRITER \*/ ${1}raptor_world_get_option_description${3}|g;
s|^(.*)(raptor_xml_writer_get_feature)(.*)$|/\* WARNING: raptor_xml_writer_get_feature.  \*/ ${1}raptor_xml_writer_get_option${3}|g;
s|^(.*)(raptor_xml_writer_get_feature_string)(.*)$|/\* WARNING: raptor_xml_writer_get_feature_string.  \*/ ${1}raptor_xml_writer_get_option${3}|g;
s|^(.*)(raptor_xml_writer_set_feature)(.*)$|/\* WARNING: raptor_xml_writer_set_feature.  \*/ ${1}raptor_xml_writer_set_option${3}|g;
s|^(.*)(raptor_xml_writer_set_feature_string)(.*)$|/\* WARNING: raptor_xml_writer_set_feature_string.  \*/ ${1}raptor_xml_writer_set_option${3}|g;

# Changed types
s|^(.*)(raptor_feature)(.*)$|/\* WARNING: raptor_feature. And new option RAPTOR_OPTION_STRICT added. \*/ ${1}raptor_option${3}|g;
s|^(.*)(raptor_graph_handler)(.*)$|/\* WARNING: raptor_graph_handler.  \*/ ${1}raptor_graph_mark_handler${3}|g;
s|^(.*)(raptor_identifier)(.*)$|/\* WARNING: raptor_identifier. Fields changed to be simpler #raptor_term_type and #raptor_term_value \*/ ${1}raptor_term${3}|g;
s|^(.*)(raptor_identifier_type)(.*)$|/\* WARNING: raptor_identifier_type. Removed several enum values to leave just URI, blank and literal types. \*/ ${1}raptor_term_type${3}|g;
s|^(.*)(raptor_iostream_handler2)(.*)$|/\* WARNING: raptor_iostream_handler2.  \*/ ${1}raptor_iostream_handler${3}|g;
s|^(.*)(raptor_iostream_write_end_func)(.*)$|/\* WARNING: raptor_iostream_write_end_func. handler returns an int \*/ ${1}raptor_iostream_write_end_func${3}|g;
s|^(.*)(raptor_log_level)(.*)$|/\* WARNING: raptor_log_level. Added RAPTOR_LOG_LEVEL_TRACE, RAPTOR_LOG_LEVEL_DEBUG, RAPTOR_LOG_LEVEL_INFO. RAPTOR_LOG_LEVEL_WARNING renamed RAPTOR_LOG_LEVEL_WARN \*/ ${1}raptor_log_level${3}|g;
s|^(.*)(raptor_sequence_free_function)(.*)$|/\* WARNING: raptor_sequence_free_function.  \*/ ${1}raptor_data_free_handler${3}|g;
s|^(.*)(raptor_sequence_free_handler_v2)(.*)$|/\* WARNING: raptor_sequence_free_handler_v2.  \*/ ${1}raptor_data_context_free_handler${3}|g;
s|^(.*)(raptor_sequence_print_handler)(.*)$|/\* WARNING: raptor_sequence_print_handler.  \*/ ${1}raptor_data_print_handler${3}|g;
s|^(.*)(raptor_sequence_print_handler_v2)(.*)$|/\* WARNING: raptor_sequence_print_handler_v2.  \*/ ${1}raptor_data_context_print_handler${3}|g;
s|^(.*)(raptor_simple_message_handler)(.*)$|/\* WARNING: raptor_simple_message_handler. Replaced by generic raptor log mechanism.  See raptor_world_set_log_handler() \*/ ${1}raptor_log_handler${3}|g;
s|^(.*)(raptor_statement)(.*)$|/\* WARNING: raptor_statement. fields changed to use #raptor_term \*/ ${1}raptor_statement${3}|g;
s|^(.*)(raptor_statement_handler)(.*)$|/\* WARNING: raptor_statement_handler. added const \*/ ${1}raptor_statement_handler${3}|g;
s|^(.*)(raptor_statement_v2)(.*)$|/\* WARNING: raptor_statement_v2. Fields changed to be a 3 or 4 tuple of #raptor_term \*/ ${1}raptor_statement${3}|g;
# Perl script to upgrade raptor2 2.0.3 to 2.0.4


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
# Perl script to upgrade raptor2 2.0.4 to 2.0.5


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
# Perl script to upgrade raptor2 2.0.5 to 2.0.6


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
# Perl script to upgrade raptor2 2.0.6 to 2.0.7


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
# Perl script to upgrade raptor2 2.0.7 to 2.0.8


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
# Perl script to upgrade raptor2 2.0.9 to 2.0.10


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
# Perl script to upgrade raptor2 2.0.10 to 2.0.11


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
# Perl script to upgrade raptor2 2.0.11 to 2.0.12


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
# Perl script to upgrade raptor2 2.0.13 to 2.0.14


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
# Perl script to upgrade raptor2 2.0.14 to 2.0.15


# Replace statement fields with term fields.
s|->object|->object.value.uri or object.value.literal.string or object.value.blank.string /* WARNING: must choose one */|g;
s|->subject_type|->subject.type|g;
s|->object_type|->object.type|g;
s|->subject|->subject.value.uri or subject.value.blank.string /* WARNING: must choose one */|g;
s|->predicate|->predicate.value.uri|g;
s|->object_literal_datatype|->object.value.literal.datatype|g;
s|->predicate_type|->predicate.type|g;
s|->object_literal_language|->object.value.literal.language|g;


# Deleted functions

# Deleted types

# Deleted enums

# Renamed functions

# Renamed enums

# Changed functions

# Changed types
