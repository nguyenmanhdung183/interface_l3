static
gnb_return_et
gnb_il_parse_rrc_mnc
(
    rrc_mnc_t * p_rrc_mnc,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
){
	    SInt32 length_read = 0;
	    *p_length_read = 0;
	
	    memset(p_rrc_mnc, 0, sizeof(rrc_mnc_t));
	
	    /* This function parses rrc_mnc */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Parsing rrc_mnc");
	
	
	/*----> UInt8 ~ count <----*/ 
	    if (*p_length_read + (SInt32)sizeof(UInt8) > length_left)
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
		        return GNB_FAILURE;
	    }
	    /* Parse/Unpack parameter of basic type */
	    gnb_cp_unpack_UInt8(&p_rrc_mnc->count, p_src + *p_length_read, "count");
	    *p_length_read += sizeof(p_rrc_mnc->count);
	    
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_rrc_mnc->count < 2.0 || p_rrc_mnc->count > MAX_MNC_OCTET_SIZE) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_rrc_mnc->count should be in range [ 2.0 - MAX_MNC_OCTET_SIZE]"
		            "Incorrect value: %d", p_rrc_mnc->count);
		        return GNB_FAILURE;
	    }
	
	/*----> UInt8 ~ mnc <----*/ 
	    /* Parse OCTET_STRING VARIABLE of basic type elements */
	    {
		        gnb_counter_t loop;
		        for(loop = 0; loop < p_rrc_mnc->count; loop++)
		        {
			            gnb_cp_unpack_UInt8((void*)(&p_rrc_mnc->mnc[loop]), (void*)(p_src + *p_length_read), "mnc[]");
			            *p_length_read += sizeof(UInt8);
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


static
gnb_return_et
gnb_il_parse_rrc_plmn_identity
(
    rrc_plmn_identity_t * p_rrc_plmn_identity,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
){
	    SInt32 length_read = 0;
	    *p_length_read = 0;
	
	    memset(p_rrc_plmn_identity, 0, sizeof(rrc_plmn_identity_t));
	
	    /* This function parses rrc_plmn_identity */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Parsing rrc_plmn_identity");
	
	
	/*----> UInt16 ~ presence_bitmask <----*/ 
	    if (*p_length_read + (SInt32)sizeof(UInt16) > length_left)
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
		        return GNB_FAILURE;
	    }
	    /* Parse/Unpack parameter of basic type */
	    gnb_cp_unpack_UInt16(&p_rrc_plmn_identity->presence_bitmask, p_src + *p_length_read, "presence_bitmask");
	    *p_length_read += sizeof(p_rrc_plmn_identity->presence_bitmask);
	    
	
	/*----> UInt8 ~ mcc <----*/ 
	    /* Optional element */
	    if(p_rrc_plmn_identity->bitmask & PLMN_IDENTITY_MCC_PRESENCE_FLAG)
	    {
		    /* Parse of OCTET_STRING FIXED of basic type elements */
		    {
			        gnb_counter_t loop;
			        for(loop = 0; loop < ARRSIZE(p_rrc_plmn_identity->mcc); loop++)
			        {
				            gnb_cp_unpack_UInt8((void*)(&p_rrc_plmn_identity->mcc[loop]), (void*)(p_src + *p_length_read), "mcc[]");
				            *p_length_read += sizeof(UInt8);
			        }
		    }
	    }
	
	/*----> rrc_mnc_t ~ mnc <----*/ 
	    /* Parse/Unpack IE */
	    if(GNB_FAILURE == gnb_il_parse_rrc_mnc(
	        &p_rrc_plmn_identity->mnc, 
	        p_src + *p_length_read, 
	        length_left - *p_length_read,
	        &length_read))
	    {
		        return GNB_FAILURE;
	    }
	
	    *p_length_read += length_read;
	
	/* final check */
	    if(*p_length_read > length_left)
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
		        return GNB_FAILURE;
	    }
	
	    return GNG_SUCCESS;
}


static
gnb_return_et
gnb_il_parse_rrc_nr_cell_identity
(
    rrc_nr_cell_identity_t * p_rrc_nr_cell_identity,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
){
	    SInt32 length_read = 0;
	    *p_length_read = 0;
	
	    memset(p_rrc_nr_cell_identity, 0, sizeof(rrc_nr_cell_identity_t));
	
	    /* This function parses rrc_nr_cell_identity */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Parsing rrc_nr_cell_identity");
	
	
	/*----> UInt32 ~ numbits <----*/ 
	    if (*p_length_read + (SInt32)sizeof(UInt32) > length_left)
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
		        return GNB_FAILURE;
	    }
	    /* Parse/Unpack parameter of basic type */
	    gnb_cp_unpack_UInt32(&p_rrc_nr_cell_identity->numbits, p_src + *p_length_read, "numbits");
	    *p_length_read += sizeof(p_rrc_nr_cell_identity->numbits);
	    
	
	/*----> UInt8 ~ data <----*/ 
	    /* Parse OCTET_STRING VARIABLE of basic type elements */
	    {
		        gnb_counter_t loop;
		        for(loop = 0; loop < p_rrc_nr_cell_identity->numbits; loop++)
		        {
			            gnb_cp_unpack_UInt8((void*)(&p_rrc_nr_cell_identity->data[loop]), (void*)(p_src + *p_length_read), "data[]");
			            *p_length_read += sizeof(UInt8);
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


static
gnb_return_et
gnb_il_parse_rrc_ncgi
(
    rrc_ncgi_t * p_rrc_ncgi,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
){
	    SInt32 length_read = 0;
	    *p_length_read = 0;
	
	    memset(p_rrc_ncgi, 0, sizeof(rrc_ncgi_t));
	
	    /* This function parses rrc_ncgi */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Parsing rrc_ncgi");
	
	
	/*----> rrc_plmn_identity_t ~ plmn_identity <----*/ 
	    /* Parse/Unpack IE */
	    if(GNB_FAILURE == gnb_il_parse_rrc_plmn_identity(
	        &p_rrc_ncgi->plmn_identity, 
	        p_src + *p_length_read, 
	        length_left - *p_length_read,
	        &length_read))
	    {
		        return GNB_FAILURE;
	    }
	
	    *p_length_read += length_read;
	
	/*----> rrc_nr_cell_identity_t ~ nr_cell_identity <----*/ 
	    /* Parse/Unpack IE */
	    if(GNB_FAILURE == gnb_il_parse_rrc_nr_cell_identity(
	        &p_rrc_ncgi->nr_cell_identity, 
	        p_src + *p_length_read, 
	        length_left - *p_length_read,
	        &length_read))
	    {
		        return GNB_FAILURE;
	    }
	
	    *p_length_read += length_read;
	
	/* final check */
	    if(*p_length_read > length_left)
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
		        return GNB_FAILURE;
	    }
	
	    return GNG_SUCCESS;
}


static
gnb_return_et
gnb_il_parse_e2_report_mobility_req
(
    e2_report_mobility_req_t * p_e2_report_mobility_req,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
){
	    SInt32 length_read = 0;
	    *p_length_read = 0;
	
	    memset(p_e2_report_mobility_req, 0, sizeof(e2_report_mobility_req_t));
	
	    /* This function parses e2_report_mobility_req */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Parsing e2_report_mobility_req");
	
	
	/*----> UInt8 ~ is_ho_attempt <----*/ 
	    if (*p_length_read + (SInt32)sizeof(UInt8) > length_left)
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
		        return GNB_FAILURE;
	    }
	    /* Parse/Unpack parameter of basic type */
	    gnb_cp_unpack_UInt8(&p_e2_report_mobility_req->is_ho_attempt, p_src + *p_length_read, "is_ho_attempt");
	    *p_length_read += sizeof(p_e2_report_mobility_req->is_ho_attempt);
	    
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_e2_report_mobility_req->is_ho_attempt < 0.0 || p_e2_report_mobility_req->is_ho_attempt > 1) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2_report_mobility_req->is_ho_attempt should be in range [ 0.0 - 1]"
		            "Incorrect value: %d", p_e2_report_mobility_req->is_ho_attempt);
		        return GNB_FAILURE;
	    }
	
	/*----> UInt8 ~ is_ho_succ <----*/ 
	    if (*p_length_read + (SInt32)sizeof(UInt8) > length_left)
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
		        return GNB_FAILURE;
	    }
	    /* Parse/Unpack parameter of basic type */
	    gnb_cp_unpack_UInt8(&p_e2_report_mobility_req->is_ho_succ, p_src + *p_length_read, "is_ho_succ");
	    *p_length_read += sizeof(p_e2_report_mobility_req->is_ho_succ);
	    
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_e2_report_mobility_req->is_ho_succ < 0.0 || p_e2_report_mobility_req->is_ho_succ > 1) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2_report_mobility_req->is_ho_succ should be in range [ 0.0 - 1]"
		            "Incorrect value: %d", p_e2_report_mobility_req->is_ho_succ);
		        return GNB_FAILURE;
	    }
	
	/*----> UInt8 ~ is_ho_failure <----*/ 
	    if (*p_length_read + (SInt32)sizeof(UInt8) > length_left)
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
		        return GNB_FAILURE;
	    }
	    /* Parse/Unpack parameter of basic type */
	    gnb_cp_unpack_UInt8(&p_e2_report_mobility_req->is_ho_failure, p_src + *p_length_read, "is_ho_failure");
	    *p_length_read += sizeof(p_e2_report_mobility_req->is_ho_failure);
	    
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_e2_report_mobility_req->is_ho_failure < 0.0 || p_e2_report_mobility_req->is_ho_failure > 1) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2_report_mobility_req->is_ho_failure should be in range [ 0.0 - 1]"
		            "Incorrect value: %d", p_e2_report_mobility_req->is_ho_failure);
		        return GNB_FAILURE;
	    }
	
	/* final check */
	    if(*p_length_read > length_left)
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
		        return GNB_FAILURE;
	    }
	
	    return GNG_SUCCESS;
}


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


