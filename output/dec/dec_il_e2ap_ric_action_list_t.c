static
gnb_return_et
gnb_il_parse_e2ap_ric_action_list
(
    e2ap_ric_action_list_t * p_e2ap_ric_action_list,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
){
    SInt32 length_read = 0;
    *p_length_read = 0;

    memset(p_e2ap_ric_action_list, 0, sizeof(e2ap_ric_action_list_t));

    /* This function parses e2ap_ric_action_list */
    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Parsing e2ap_ric_action_list");


/*----> UInt16 ~ bitmask <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt16) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt16(&p_e2ap_ric_action_list->bitmask, p_src + *p_length_read, "bitmask");
    *p_length_read += sizeof(p_e2ap_ric_action_list->bitmask);
    

/*----> UInt32 ~ report_period_ms <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt32) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt32(&p_e2ap_ric_action_list->report_period_ms, p_src + *p_length_read, "report_period_ms");
    *p_length_read += sizeof(p_e2ap_ric_action_list->report_period_ms);
    

/*----> UInt32 ~ action_id <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt32) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt32(&p_e2ap_ric_action_list->action_id, p_src + *p_length_read, "action_id");
    *p_length_read += sizeof(p_e2ap_ric_action_list->action_id);
    

/*----> UInt8 ~ action_type <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt8) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt8(&p_e2ap_ric_action_list->action_type, p_src + *p_length_read, "action_type");
    *p_length_read += sizeof(p_e2ap_ric_action_list->action_type);
    
    /* Check for correct range [L - lower boundary] */
    if(p_e2ap_ric_action_list->action_type < 0.0)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2ap_ric_action_list->action_type should be greater than or equal to 0.0"
            "Incorrect value: %d", p_e2ap_ric_action_list->action_type);
        return GNB_FAILURE;
    }

/*----> rrc_ncgi_t ~ nr_cgi <----*/ 
    /* Parse/Unpack IE */
    if(GNB_FAILURE == gnb_il_parse_rrc_ncgi(
        &p_e2ap_ric_action_list->nr_cgi, 
        p_src + *p_length_read, 
        length_left - *p_length_read,
        &length_read))
    {
        return GNB_FAILURE;
    }

    *p_length_read += length_read;

/*----> e2_report_mobility_req_t ~ report_mobility_req <----*/ 
    /* Optional element */
    if(p_e2ap_ric_action_list->bitmask & E2AP_REPORT_MOBILITY)
    {
    /* Parse/Unpack IE */
    if(GNB_FAILURE == gnb_il_parse_e2_report_mobility_req(
        &p_e2ap_ric_action_list->report_mobility_req, 
        p_src + *p_length_read, 
        length_left - *p_length_read,
        &length_read))
    {
        return GNB_FAILURE;
    }

    *p_length_read += length_read;
    }

/* final check */
    if(*p_length_read > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }

    return GNG_SUCCESS;
}


