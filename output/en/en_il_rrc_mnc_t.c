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


