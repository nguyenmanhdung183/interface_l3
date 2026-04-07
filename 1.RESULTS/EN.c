/* get length */
static
gnb_length_t
gnb_il_get_rrc_mnc_len 
(
    rrc_mnc_t * p_rrc_mnc
){
	    gnb_length_t length = 0;
	    GNB_ASSERT(p_rrc_mnc != GNB_P_NULL);
	
	/*----> UInt8 ~ count <----*/ 
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_rrc_mnc->count < 2.0 || p_rrc_mnc->count > MAX_MNC_OCTET_SIZE) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_rrc_mnc->count should be in range [ 2.0 - MAX_MNC_OCTET_SIZE]"
		            "Incorrect value: %d", p_rrc_mnc->count);
		        return GNB_FAILURE;
	    }
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_rrc_mnc->count);
	
	/*----> UInt8 ~ mnc <----*/ 
	    /* Get length of OCTET_STRING VARIABLE of basic type elements */
	    length += (p_rrc_mnc->count * sizeof(p_rrc_mnc->mnc[0]));
	
	
	    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_rrc_mnc
(
    UInt8 **pp_buffer,
    rrc_mnc_t * p_rrc_mnc
){
	    GNB_ASSERT(pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(p_rrc_mnc != GNB_P_NULL);
	
	    /* This function composes rrc_mnc */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing rrc_mnc");
	
	/*----> UInt8 ~ count <----*/ 
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_rrc_mnc->count < 2.0 || p_rrc_mnc->count > MAX_MNC_OCTET_SIZE) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_rrc_mnc->count should be in range [ 2.0 - MAX_MNC_OCTET_SIZE]"
		            "Incorrect value: %d", p_rrc_mnc->count);
		        return GNB_FAILURE;
	    }
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt8(*pp_buffer, &p_rrc_mnc->count, "count");
	    *pp_buffer += sizeof(p_rrc_mnc->count);
	
	/*----> UInt8 ~ mnc <----*/ 
	    /* Compose OCTET_STRING VARIABLE of basic type elements */
	    {
		        gnb_counter_t loop;
		        for(loop = 0; loop < p_rrc_mnc->count; loop++)
		        {
			            gnb_cp_pack_UInt8(*pp_buffer, &p_rrc_mnc->mnc[loop], "mnc[]");
			            *pp_buffer += sizeof(UInt8);
		        }
	    }
	
	
	    return GNG_SUCCESS;
}


/* get length */
static
gnb_length_t
gnb_il_get_rrc_plmn_identity_len 
(
    rrc_plmn_identity_t * p_rrc_plmn_identity
){
	    gnb_length_t length = 0;
	    GNB_ASSERT(p_rrc_plmn_identity != GNB_P_NULL);
	
	/*----> UInt16 ~ presence_bitmask <----*/ 
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_rrc_plmn_identity->presence_bitmask);
	
	/*----> UInt8 ~ mcc <----*/ 
	    /* Optional element */
	    if(p_rrc_plmn_identity->bitmask & PLMN_IDENTITY_MCC_PRESENCE_FLAG)
	    {
		    /* Get length of OCTET_STRING FIXED of basic type elements */
		    length += sizeof(p_rrc_plmn_identity->mcc);
	    }
	
	/*----> rrc_mnc_t ~ mnc <----*/ 
	    /* Get length of IE */
	    length += gnb_il_get_rrc_mnc_len(&p_rrc_plmn_identity->mnc);
	
	
	    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_rrc_plmn_identity
(
    UInt8 **pp_buffer,
    rrc_plmn_identity_t * p_rrc_plmn_identity
){
	    GNB_ASSERT(pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(p_rrc_plmn_identity != GNB_P_NULL);
	
	    /* This function composes rrc_plmn_identity */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing rrc_plmn_identity");
	
	/*----> UInt16 ~ presence_bitmask <----*/ 
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt16(*pp_buffer, &p_rrc_plmn_identity->presence_bitmask, "presence_bitmask");
	    *pp_buffer += sizeof(p_rrc_plmn_identity->presence_bitmask);
	
	/*----> UInt8 ~ mcc <----*/ 
	    /* Optional element */
	    if(p_rrc_plmn_identity->bitmask & PLMN_IDENTITY_MCC_PRESENCE_FLAG)
	    {
		    /* Compose of OCTET_STRING FIXED of basic type elements */
		    {
			        gnb_counter_t loop;
			        for(loop = 0; loop < ARRSIZE(p_rrc_plmn_identity->mcc); loop++)
			        {
				            gnb_cp_pack_UInt8(*pp_buffer, &p_rrc_plmn_identity->mcc[loop], "mcc[]");
				            *pp_buffer += sizeof(UInt8);
			        }
		    }
	    }
	
	/*----> rrc_mnc_t ~ mnc <----*/ 
	    /* Compose IE */
	    if(GNB_FAILURE == gnb_il_compose_rrc_mnc(pp_buffer, &p_rrc_plmn_identity->mnc))
	    {
		        return GNB_FAILURE;
	    }
	
	
	    return GNG_SUCCESS;
}


/* get length */
static
gnb_length_t
gnb_il_get_rrc_nr_cell_identity_len 
(
    rrc_nr_cell_identity_t * p_rrc_nr_cell_identity
){
	    gnb_length_t length = 0;
	    GNB_ASSERT(p_rrc_nr_cell_identity != GNB_P_NULL);
	
	/*----> UInt32 ~ numbits <----*/ 
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_rrc_nr_cell_identity->numbits);
	
	/*----> UInt8 ~ data <----*/ 
	    /* Get length of OCTET_STRING VARIABLE of basic type elements */
	    length += (p_rrc_nr_cell_identity->numbits * sizeof(p_rrc_nr_cell_identity->data[0]));
	
	
	    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_rrc_nr_cell_identity
(
    UInt8 **pp_buffer,
    rrc_nr_cell_identity_t * p_rrc_nr_cell_identity
){
	    GNB_ASSERT(pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(p_rrc_nr_cell_identity != GNB_P_NULL);
	
	    /* This function composes rrc_nr_cell_identity */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing rrc_nr_cell_identity");
	
	/*----> UInt32 ~ numbits <----*/ 
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt32(*pp_buffer, &p_rrc_nr_cell_identity->numbits, "numbits");
	    *pp_buffer += sizeof(p_rrc_nr_cell_identity->numbits);
	
	/*----> UInt8 ~ data <----*/ 
	    /* Compose OCTET_STRING VARIABLE of basic type elements */
	    {
		        gnb_counter_t loop;
		        for(loop = 0; loop < p_rrc_nr_cell_identity->numbits; loop++)
		        {
			            gnb_cp_pack_UInt8(*pp_buffer, &p_rrc_nr_cell_identity->data[loop], "data[]");
			            *pp_buffer += sizeof(UInt8);
		        }
	    }
	
	
	    return GNG_SUCCESS;
}


/* get length */
static
gnb_length_t
gnb_il_get_rrc_ncgi_len 
(
    rrc_ncgi_t * p_rrc_ncgi
){
	    gnb_length_t length = 0;
	    GNB_ASSERT(p_rrc_ncgi != GNB_P_NULL);
	
	/*----> rrc_plmn_identity_t ~ plmn_identity <----*/ 
	    /* Get length of IE */
	    length += gnb_il_get_rrc_plmn_identity_len(&p_rrc_ncgi->plmn_identity);
	
	/*----> rrc_nr_cell_identity_t ~ nr_cell_identity <----*/ 
	    /* Get length of IE */
	    length += gnb_il_get_rrc_nr_cell_identity_len(&p_rrc_ncgi->nr_cell_identity);
	
	
	    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_rrc_ncgi
(
    UInt8 **pp_buffer,
    rrc_ncgi_t * p_rrc_ncgi
){
	    GNB_ASSERT(pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(p_rrc_ncgi != GNB_P_NULL);
	
	    /* This function composes rrc_ncgi */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing rrc_ncgi");
	
	/*----> rrc_plmn_identity_t ~ plmn_identity <----*/ 
	    /* Compose IE */
	    if(GNB_FAILURE == gnb_il_compose_rrc_plmn_identity(pp_buffer, &p_rrc_ncgi->plmn_identity))
	    {
		        return GNB_FAILURE;
	    }
	
	/*----> rrc_nr_cell_identity_t ~ nr_cell_identity <----*/ 
	    /* Compose IE */
	    if(GNB_FAILURE == gnb_il_compose_rrc_nr_cell_identity(pp_buffer, &p_rrc_ncgi->nr_cell_identity))
	    {
		        return GNB_FAILURE;
	    }
	
	
	    return GNG_SUCCESS;
}


/* get length */
static
gnb_length_t
gnb_il_get_e2_report_mobility_req_len 
(
    e2_report_mobility_req_t * p_e2_report_mobility_req
){
	    gnb_length_t length = 0;
	    GNB_ASSERT(p_e2_report_mobility_req != GNB_P_NULL);
	
	/*----> UInt8 ~ is_ho_attempt <----*/ 
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_e2_report_mobility_req->is_ho_attempt < 0.0 || p_e2_report_mobility_req->is_ho_attempt > 1) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2_report_mobility_req->is_ho_attempt should be in range [ 0.0 - 1]"
		            "Incorrect value: %d", p_e2_report_mobility_req->is_ho_attempt);
		        return GNB_FAILURE;
	    }
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_e2_report_mobility_req->is_ho_attempt);
	
	/*----> UInt8 ~ is_ho_succ <----*/ 
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_e2_report_mobility_req->is_ho_succ < 0.0 || p_e2_report_mobility_req->is_ho_succ > 1) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2_report_mobility_req->is_ho_succ should be in range [ 0.0 - 1]"
		            "Incorrect value: %d", p_e2_report_mobility_req->is_ho_succ);
		        return GNB_FAILURE;
	    }
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_e2_report_mobility_req->is_ho_succ);
	
	/*----> UInt8 ~ is_ho_failure <----*/ 
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_e2_report_mobility_req->is_ho_failure < 0.0 || p_e2_report_mobility_req->is_ho_failure > 1) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2_report_mobility_req->is_ho_failure should be in range [ 0.0 - 1]"
		            "Incorrect value: %d", p_e2_report_mobility_req->is_ho_failure);
		        return GNB_FAILURE;
	    }
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_e2_report_mobility_req->is_ho_failure);
	
	
	    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_e2_report_mobility_req
(
    UInt8 **pp_buffer,
    e2_report_mobility_req_t * p_e2_report_mobility_req
){
	    GNB_ASSERT(pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(p_e2_report_mobility_req != GNB_P_NULL);
	
	    /* This function composes e2_report_mobility_req */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing e2_report_mobility_req");
	
	/*----> UInt8 ~ is_ho_attempt <----*/ 
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_e2_report_mobility_req->is_ho_attempt < 0.0 || p_e2_report_mobility_req->is_ho_attempt > 1) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2_report_mobility_req->is_ho_attempt should be in range [ 0.0 - 1]"
		            "Incorrect value: %d", p_e2_report_mobility_req->is_ho_attempt);
		        return GNB_FAILURE;
	    }
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt8(*pp_buffer, &p_e2_report_mobility_req->is_ho_attempt, "is_ho_attempt");
	    *pp_buffer += sizeof(p_e2_report_mobility_req->is_ho_attempt);
	
	/*----> UInt8 ~ is_ho_succ <----*/ 
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_e2_report_mobility_req->is_ho_succ < 0.0 || p_e2_report_mobility_req->is_ho_succ > 1) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2_report_mobility_req->is_ho_succ should be in range [ 0.0 - 1]"
		            "Incorrect value: %d", p_e2_report_mobility_req->is_ho_succ);
		        return GNB_FAILURE;
	    }
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt8(*pp_buffer, &p_e2_report_mobility_req->is_ho_succ, "is_ho_succ");
	    *pp_buffer += sizeof(p_e2_report_mobility_req->is_ho_succ);
	
	/*----> UInt8 ~ is_ho_failure <----*/ 
	    /* Check for correct range [B - both higher and lower boundary] */
	    if(p_e2_report_mobility_req->is_ho_failure < 0.0 || p_e2_report_mobility_req->is_ho_failure > 1) 
	    {
		        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Parameter p_e2_report_mobility_req->is_ho_failure should be in range [ 0.0 - 1]"
		            "Incorrect value: %d", p_e2_report_mobility_req->is_ho_failure);
		        return GNB_FAILURE;
	    }
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt8(*pp_buffer, &p_e2_report_mobility_req->is_ho_failure, "is_ho_failure");
	    *pp_buffer += sizeof(p_e2_report_mobility_req->is_ho_failure);
	
	
	    return GNG_SUCCESS;
}


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


/* get length */
static
gnb_length_t
gnb_il_get_rrc_e2sm_kpm_ric_sub_req_len 
(
    rrc_e2sm_kpm_ric_sub_req_t * p_rrc_e2sm_kpm_ric_sub_req
){
	    gnb_length_t length = 0;
	    GNB_ASSERT(p_rrc_e2sm_kpm_ric_sub_req != GNB_P_NULL);
	
	/*----> UInt32 ~ ric_request_id <----*/ 
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_rrc_e2sm_kpm_ric_sub_req->ric_request_id);
	
	/*----> UInt16 ~ ran_function_id <----*/ 
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_rrc_e2sm_kpm_ric_sub_req->ran_function_id);
	
	/*----> UInt8 ~ num_action <----*/ 
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_rrc_e2sm_kpm_ric_sub_req->num_action);
	
	/*----> UInt8 ~ periodic <----*/ 
	    /* Get length of parameter of basic type */
	    length += (gnb_length_t)sizeof(p_rrc_e2sm_kpm_ric_sub_req->periodic);
	
	/*----> e2ap_ric_action_list_t ~ action_list <----*/ 
	    /* Get length of OCTET_STRING VARIABLE of IE */
	    {
		        gnb_counter_t loop;
		        for(loop = 0; loop < p_rrc_e2sm_kpm_ric_sub_req->num_action; loop++)
		        {
			            length += gnb_il_get_e2ap_ric_action_list_len(&p_rrc_e2sm_kpm_ric_sub_req->action_list[loop]);
		        }
	    }
	
	
	    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_rrc_e2sm_kpm_ric_sub_req
(
    UInt8 **pp_buffer,
    rrc_e2sm_kpm_ric_sub_req_t * p_rrc_e2sm_kpm_ric_sub_req
){
	    GNB_ASSERT(pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
	    GNB_ASSERT(p_rrc_e2sm_kpm_ric_sub_req != GNB_P_NULL);
	
	    /* This function composes rrc_e2sm_kpm_ric_sub_req */
	    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing rrc_e2sm_kpm_ric_sub_req");
	
	/*----> UInt32 ~ ric_request_id <----*/ 
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt32(*pp_buffer, &p_rrc_e2sm_kpm_ric_sub_req->ric_request_id, "ric_request_id");
	    *pp_buffer += sizeof(p_rrc_e2sm_kpm_ric_sub_req->ric_request_id);
	
	/*----> UInt16 ~ ran_function_id <----*/ 
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt16(*pp_buffer, &p_rrc_e2sm_kpm_ric_sub_req->ran_function_id, "ran_function_id");
	    *pp_buffer += sizeof(p_rrc_e2sm_kpm_ric_sub_req->ran_function_id);
	
	/*----> UInt8 ~ num_action <----*/ 
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt8(*pp_buffer, &p_rrc_e2sm_kpm_ric_sub_req->num_action, "num_action");
	    *pp_buffer += sizeof(p_rrc_e2sm_kpm_ric_sub_req->num_action);
	
	/*----> UInt8 ~ periodic <----*/ 
	    /* Compose parameter of basic type */
	    gnb_cp_pack_UInt8(*pp_buffer, &p_rrc_e2sm_kpm_ric_sub_req->periodic, "periodic");
	    *pp_buffer += sizeof(p_rrc_e2sm_kpm_ric_sub_req->periodic);
	
	/*----> e2ap_ric_action_list_t ~ action_list <----*/ 
	    /* Compose OCTET_STRING VARIABLE of IE */
	    {
		        gnb_counter_t loop;
		        for(loop = 0; loop < p_rrc_e2sm_kpm_ric_sub_req->num_action; loop++)
		        {
			            if(GNB_FAILURE == gnb_il_compose_e2ap_ric_action_list(pp_buffer, &p_rrc_e2sm_kpm_ric_sub_req->action_list[loop]))
			            {
				                return GNB_FAILURE;
			            }
		        }
	    }
	
	
	    return GNG_SUCCESS;
}


