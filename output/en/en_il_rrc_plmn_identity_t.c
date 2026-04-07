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


