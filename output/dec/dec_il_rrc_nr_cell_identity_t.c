static
gnb_return_et
gnb_il_parse_rrc_nr_cell_identity
(
    rrc_nr_cell_identity_t * p_rrc_nr_cell_identity,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
){
    SInt32 length_read = 0;
    *p_length_read = 0;

    memset(p_rrc_nr_cell_identity, 0, sizeof(rrc_nr_cell_identity_t));

    /* This function parses rrc_nr_cell_identity */
    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Parsing rrc_nr_cell_identity");


/*----> UInt32 ~ numbits <----*/ 
    if (*p_length_read + (SInt32)sizeof(UInt32) > length_left)
    {
        GNB_CP_TRACE(GNB_WARNING, "dungnm26 - Incomming message damaged!");
        return GNB_FAILURE;
    }
    /* Parse/Unpack parameter of basic type */
    gnb_cp_unpack_UInt32(&p_rrc_nr_cell_identity->numbits, p_src + *p_length_read, "numbits");
    *p_length_read += sizeof(p_rrc_nr_cell_identity->numbits);
    

/*----> UInt8 ~ data <----*/ 
    /* Parse OCTET_STRING VARIABLE of basic type elements */
    {
        gnb_counter_t loop;
        for(loop = 0; loop < p_rrc_nr_cell_identity->numbits; loop++)
        {
            gnb_cp_unpack_UInt8((void*)(&p_rrc_nr_cell_identity->data[loop]), (void*)(p_src + *p_length_read), "data[]");
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


