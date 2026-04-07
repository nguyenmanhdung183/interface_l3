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


