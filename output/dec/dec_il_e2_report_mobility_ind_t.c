static
gnb_return_et
gnb_il_parse_e2_report_mobility_ind
(
    e2_report_mobility_ind_t * p_e2_report_mobility_ind,
    UInt8 * p_src,
    UInt32 length_left,
    SInt32 * p_length_read
){
    SInt32 length_read = 0;
    *p_length_read = 0;

    memset(p_e2_report_mobility_ind, 0, sizeof(e2_report_mobility_ind_t));

    /* This function parses e2_report_mobility_ind */
    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Parsing e2_report_mobility_ind");


/*----> UInt32 ~ ho_attempt <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt32) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt32(&p_e2_report_mobility_ind->ho_attempt, p_src + *p_length_read, "ho_attempt");
    *p_length_read += sizeof(p_e2_report_mobility_ind->ho_attempt);
    

/*----> UInt32 ~ ho_succ <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt32) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt32(&p_e2_report_mobility_ind->ho_succ, p_src + *p_length_read, "ho_succ");
    *p_length_read += sizeof(p_e2_report_mobility_ind->ho_succ);
    

/*----> UInt32 ~ ho_failure <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt32) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt32(&p_e2_report_mobility_ind->ho_failure, p_src + *p_length_read, "ho_failure");
    *p_length_read += sizeof(p_e2_report_mobility_ind->ho_failure);
    

/* final check */
    if(*p_length_read > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }

    return GNG_SUCCESS;
}


