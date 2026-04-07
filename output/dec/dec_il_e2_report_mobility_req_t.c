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


