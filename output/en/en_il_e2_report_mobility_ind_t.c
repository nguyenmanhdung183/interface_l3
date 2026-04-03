/* get length */
static
gnb_length_t
gnb_il_get_e2_report_mobility_ind_len 
(
    e2_report_mobility_ind_t * p_e2_report_mobility_ind
){
    gnb_length_t length = 0;
    GNB_ASSERT(p_e2_report_mobility_ind != GNB_P_NULL);

/*----> UInt32 ~ ho_attempt <----*/ 
    /* Get length of parameter of basic type */
    length += (gnb_length_t)sizeof(p_e2_report_mobility_ind->ho_attempt);

/*----> UInt32 ~ ho_succ <----*/ 
    /* Get length of parameter of basic type */
    length += (gnb_length_t)sizeof(p_e2_report_mobility_ind->ho_succ);

/*----> UInt32 ~ ho_failure <----*/ 
    /* Get length of parameter of basic type */
    length += (gnb_length_t)sizeof(p_e2_report_mobility_ind->ho_failure);


    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_e2_report_mobility_ind
(
    UInt8 **pp_buffer,
    e2_report_mobility_ind_t * p_e2_report_mobility_ind
){
    GNB_ASSERT(pp_buffer != GNB_P_NULL);
    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
    GNB_ASSERT(p_e2_report_mobility_ind != GNB_P_NULL);

    /* This function composes e2_report_mobility_ind */
    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing e2_report_mobility_ind");

/*----> UInt32 ~ ho_attempt <----*/ 
    /* Compose parameter of basic type */
    gnb_cp_pack_UInt32(*pp_buffer, &p_e2_report_mobility_ind->ho_attempt, "ho_attempt");
    *pp_buffer += sizeof(p_e2_report_mobility_ind->ho_attempt);

/*----> UInt32 ~ ho_succ <----*/ 
    /* Compose parameter of basic type */
    gnb_cp_pack_UInt32(*pp_buffer, &p_e2_report_mobility_ind->ho_succ, "ho_succ");
    *pp_buffer += sizeof(p_e2_report_mobility_ind->ho_succ);

/*----> UInt32 ~ ho_failure <----*/ 
    /* Compose parameter of basic type */
    gnb_cp_pack_UInt32(*pp_buffer, &p_e2_report_mobility_ind->ho_failure, "ho_failure");
    *pp_buffer += sizeof(p_e2_report_mobility_ind->ho_failure);


    return GNG_SUCCESS;
}


