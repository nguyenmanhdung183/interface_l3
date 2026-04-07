/* get length */
static
gnb_length_t
gnb_il_get_rrc_nr_cell_identity_len 
(
    rrc_nr_cell_identity_t * p_rrc_nr_cell_identity
){
    gnb_length_t length = 0;
    GNB_ASSERT(p_rrc_nr_cell_identity != GNB_P_NULL);

/*----> UInt32 ~ numbits <----*/ 
    /* Get length of parameter of basic type */
    length += (gnb_length_t)sizeof(p_rrc_nr_cell_identity->numbits);

/*----> UInt8 ~ data <----*/ 
    /* Get length of OCTET_STRING VARIABLE of basic type elements */
    length += (p_rrc_nr_cell_identity->numbits * sizeof(p_rrc_nr_cell_identity->data[0]));


    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_rrc_nr_cell_identity
(
    UInt8 **pp_buffer,
    rrc_nr_cell_identity_t * p_rrc_nr_cell_identity
){
    GNB_ASSERT(pp_buffer != GNB_P_NULL);
    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
    GNB_ASSERT(p_rrc_nr_cell_identity != GNB_P_NULL);

    /* This function composes rrc_nr_cell_identity */
    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing rrc_nr_cell_identity");

/*----> UInt32 ~ numbits <----*/ 
    /* Compose parameter of basic type */
    gnb_cp_pack_UInt32(*pp_buffer, &p_rrc_nr_cell_identity->numbits, "numbits");
    *pp_buffer += sizeof(p_rrc_nr_cell_identity->numbits);

/*----> UInt8 ~ data <----*/ 
    /* Compose OCTET_STRING VARIABLE of basic type elements */
    {
        gnb_counter_t loop;
        for(loop = 0; loop < p_rrc_nr_cell_identity->numbits; loop++)
        {
            gnb_cp_pack_UInt8(*pp_buffer, &p_rrc_nr_cell_identity->data[loop], "data[]");
            *pp_buffer += sizeof(UInt8);
        }
    }


    return GNG_SUCCESS;
}


