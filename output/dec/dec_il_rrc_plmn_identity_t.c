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


