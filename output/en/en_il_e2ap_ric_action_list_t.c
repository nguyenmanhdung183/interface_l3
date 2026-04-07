/* get length */
static
gnb_length_t
gnb_il_get_e2ap_ric_action_list_len 
(
    e2ap_ric_action_list_t * p_e2ap_ric_action_list
){
    gnb_length_t length = 0;
    GNB_ASSERT(p_e2ap_ric_action_list != GNB_P_NULL);

/*----> UInt16 ~ bitmask <----*/ 
    /* Get length of parameter of basic type */
    length += (gnb_length_t)sizeof(p_e2ap_ric_action_list->bitmask);

/*----> UInt32 ~ report_period_ms <----*/ 
    /* Get length of parameter of basic type */
    length += (gnb_length_t)sizeof(p_e2ap_ric_action_list->report_period_ms);

/*----> UInt32 ~ action_id <----*/ 
    /* Get length of parameter of basic type */
    length += (gnb_length_t)sizeof(p_e2ap_ric_action_list->action_id);

/*----> UInt8 ~ action_type <----*/ 
    /* Check for correct range [L - lower boundary] */
    if(p_e2ap_ric_action_list->action_type < 0.0)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2ap_ric_action_list->action_type should be greater than or equal to 0.0"
            "Incorrect value: %d", p_e2ap_ric_action_list->action_type);
        return GNB_FAILURE;
    }
    /* Get length of parameter of basic type */
    length += (gnb_length_t)sizeof(p_e2ap_ric_action_list->action_type);

/*----> rrc_ncgi_t ~ nr_cgi <----*/ 
    /* Get length of IE */
    length += gnb_il_get_rrc_ncgi_len(&p_e2ap_ric_action_list->nr_cgi);

/*----> e2_report_mobility_req_t ~ report_mobility_req <----*/ 
    /* Optional element */
    if(p_e2ap_ric_action_list->bitmask & E2AP_REPORT_MOBILITY)
    {
    /* Get length of IE */
    length += gnb_il_get_e2_report_mobility_req_len(&p_e2ap_ric_action_list->report_mobility_req);
    }


    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_e2ap_ric_action_list
(
    UInt8 **pp_buffer,
    e2ap_ric_action_list_t * p_e2ap_ric_action_list
){
    GNB_ASSERT(pp_buffer != GNB_P_NULL);
    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
    GNB_ASSERT(p_e2ap_ric_action_list != GNB_P_NULL);

    /* This function composes e2ap_ric_action_list */
    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing e2ap_ric_action_list");

/*----> UInt16 ~ bitmask <----*/ 
    /* Compose parameter of basic type */
    gnb_cp_pack_UInt16(*pp_buffer, &p_e2ap_ric_action_list->bitmask, "bitmask");
    *pp_buffer += sizeof(p_e2ap_ric_action_list->bitmask);

/*----> UInt32 ~ report_period_ms <----*/ 
    /* Compose parameter of basic type */
    gnb_cp_pack_UInt32(*pp_buffer, &p_e2ap_ric_action_list->report_period_ms, "report_period_ms");
    *pp_buffer += sizeof(p_e2ap_ric_action_list->report_period_ms);

/*----> UInt32 ~ action_id <----*/ 
    /* Compose parameter of basic type */
    gnb_cp_pack_UInt32(*pp_buffer, &p_e2ap_ric_action_list->action_id, "action_id");
    *pp_buffer += sizeof(p_e2ap_ric_action_list->action_id);

/*----> UInt8 ~ action_type <----*/ 
    /* Check for correct range [L - lower boundary] */
    if(p_e2ap_ric_action_list->action_type < 0.0)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2ap_ric_action_list->action_type should be greater than or equal to 0.0"
            "Incorrect value: %d", p_e2ap_ric_action_list->action_type);
        return GNB_FAILURE;
    }
    /* Compose parameter of basic type */
    gnb_cp_pack_UInt8(*pp_buffer, &p_e2ap_ric_action_list->action_type, "action_type");
    *pp_buffer += sizeof(p_e2ap_ric_action_list->action_type);

/*----> rrc_ncgi_t ~ nr_cgi <----*/ 
    /* Compose IE */
    if(GNB_FAILURE == gnb_il_compose_rrc_ncgi(pp_buffer, &p_e2ap_ric_action_list->nr_cgi))
    {
        return GNB_FAILURE;
    }

/*----> e2_report_mobility_req_t ~ report_mobility_req <----*/ 
    /* Optional element */
    if(p_e2ap_ric_action_list->bitmask & E2AP_REPORT_MOBILITY)
    {
    /* Compose IE */
    if(GNB_FAILURE == gnb_il_compose_e2_report_mobility_req(pp_buffer, &p_e2ap_ric_action_list->report_mobility_req))
    {
        return GNB_FAILURE;
    }
    }


    return GNG_SUCCESS;
}


