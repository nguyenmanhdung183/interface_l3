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


