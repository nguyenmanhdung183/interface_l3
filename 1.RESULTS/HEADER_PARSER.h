static 
gnb_return_et
gnb_il_parse_rrc_mnc 
(
    rrc_mnc_t * p_rrc_mnc,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
);

static 
gnb_return_et
gnb_il_parse_rrc_plmn_identity 
(
    rrc_plmn_identity_t * p_rrc_plmn_identity,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
);

static 
gnb_return_et
gnb_il_parse_rrc_nr_cell_identity 
(
    rrc_nr_cell_identity_t * p_rrc_nr_cell_identity,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
);

static 
gnb_return_et
gnb_il_parse_rrc_ncgi 
(
    rrc_ncgi_t * p_rrc_ncgi,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
);

static 
gnb_return_et
gnb_il_parse_e2_report_mobility_req 
(
    e2_report_mobility_req_t * p_e2_report_mobility_req,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
);

static 
gnb_return_et
gnb_il_parse_e2ap_ric_action_list 
(
    e2ap_ric_action_list_t * p_e2ap_ric_action_list,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
);

static 
gnb_return_et
gnb_il_parse_rrc_e2sm_kpm_ric_sub_req 
(
    rrc_e2sm_kpm_ric_sub_req_t * p_rrc_e2sm_kpm_ric_sub_req,
    UInt8 * p_src,
    SInt32 length_left,
    SInt32 * p_length_read
);

