/* get length */
static
gnb_length_t
gnb_il_get_rrc_ncgi_len 
(
    rrc_ncgi_t * p_rrc_ncgi
){
    gnb_length_t length = 0;
    GNB_ASSERT(p_rrc_ncgi != GNB_P_NULL);

/*----> rrc_plmn_identity_t ~ plmn_identity <----*/ 
    /* Get length of IE */
    length += gnb_il_get_rrc_plmn_identity_len(&p_rrc_ncgi->plmn_identity);

/*----> rrc_nr_cell_identity_t ~ nr_cell_identity <----*/ 
    /* Get length of IE */
    length += gnb_il_get_rrc_nr_cell_identity_len(&p_rrc_ncgi->nr_cell_identity);


    return length;
}


/* compose */
static
gnb_return_et
gnb_il_compose_rrc_ncgi
(
    UInt8 **pp_buffer,
    rrc_ncgi_t * p_rrc_ncgi
){
    GNB_ASSERT(pp_buffer != GNB_P_NULL);
    GNB_ASSERT(*pp_buffer != GNB_P_NULL);
    GNB_ASSERT(p_rrc_ncgi != GNB_P_NULL);

    /* This function composes rrc_ncgi */
    GNB_CP_TRACE(GNB_DETAILEDALL, "dungnm26 - Composing rrc_ncgi");

/*----> rrc_plmn_identity_t ~ plmn_identity <----*/ 
    /* Compose IE */
    if(GNB_FAILURE == gnb_il_compose_rrc_plmn_identity(pp_buffer, &p_rrc_ncgi->plmn_identity))
    {
        return GNB_FAILURE;
    }

/*----> rrc_nr_cell_identity_t ~ nr_cell_identity <----*/ 
    /* Compose IE */
    if(GNB_FAILURE == gnb_il_compose_rrc_nr_cell_identity(pp_buffer, &p_rrc_ncgi->nr_cell_identity))
    {
        return GNB_FAILURE;
    }


    return GNG_SUCCESS;
}


