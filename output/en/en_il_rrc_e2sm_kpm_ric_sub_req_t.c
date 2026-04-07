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


