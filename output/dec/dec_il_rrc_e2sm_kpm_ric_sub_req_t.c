static
gnb_return_et
gnb_il_parse_rrc_e2sm_kpm_ric_sub_req
(
    rrc_e2sm_kpm_ric_sub_req_t * p_rrc_e2sm_kpm_ric_sub_req,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
){
    SInt32 length_read = 0;
    *p_length_read = 0;

    memset(p_rrc_e2sm_kpm_ric_sub_req, 0, sizeof(rrc_e2sm_kpm_ric_sub_req_t));

    /* This function parses rrc_e2sm_kpm_ric_sub_req */
    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Parsing rrc_e2sm_kpm_ric_sub_req");


/*----> UInt32 ~ ric_request_id <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt32) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt32(&p_rrc_e2sm_kpm_ric_sub_req->ric_request_id, p_src + *p_length_read, "ric_request_id");
    *p_length_read += sizeof(p_rrc_e2sm_kpm_ric_sub_req->ric_request_id);
    

/*----> UInt16 ~ ran_function_id <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt16) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt16(&p_rrc_e2sm_kpm_ric_sub_req->ran_function_id, p_src + *p_length_read, "ran_function_id");
    *p_length_read += sizeof(p_rrc_e2sm_kpm_ric_sub_req->ran_function_id);
    

/*----> UInt8 ~ num_action <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt8) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt8(&p_rrc_e2sm_kpm_ric_sub_req->num_action, p_src + *p_length_read, "num_action");
    *p_length_read += sizeof(p_rrc_e2sm_kpm_ric_sub_req->num_action);
    

/*----> UInt8 ~ periodic <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt8) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt8(&p_rrc_e2sm_kpm_ric_sub_req->periodic, p_src + *p_length_read, "periodic");
    *p_length_read += sizeof(p_rrc_e2sm_kpm_ric_sub_req->periodic);
    

/*----> e2ap_ric_action_list_t ~ action_list <----*/ 
    
    /* Parse OCTET_STRING VARIABLE of IE */
    {
        gnb_counter_t loop;
        for(loop = 0; loop < p_rrc_e2sm_kpm_ric_sub_req->num_action; loop++)
        {
            if(GNB_FAILURE == gnb_il_parse_e2ap_ric_action_list(
                &p_rrc_e2sm_kpm_ric_sub_req->action_list[loop], 
                p_src + *p_length_read, 
                length_left - *p_length_read,
                &length_read))
            {
                return GNB_FAILURE;
            }
            *p_length_read += length_read;
        }
    }

/* final check */
    if(*p_length_read > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }

    return GNG_SUCCESS;
}


