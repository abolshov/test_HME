#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <vector>

#include "TH1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLegend.h"
#include "THStack.h"
#include "TLorentzVector.h"

namespace save 
{
    void save_1d_dist(TH1F* dist, std::string const& name, std::string const& title);

    void save_2d_dist(TH2F* dist, std::string const& name, std::string const& title_x, std::string const& title_y);

    void save_1d_stack(std::vector<TH1F*> const& distrs,
                       std::vector<std::string> const& legends,
                       std::string const& name,
                       std::string const& title,
                       std::string const& axis_label);    
}

namespace jet
{
    void pt_order(TLorentzVector& p1, TLorentzVector& p2);

    bool is_offshell(TLorentzVector const& p1, TLorentzVector const& p2, TLorentzVector const& l, TLorentzVector const& nu);

    std::pair<float, float> compute_resc_factors(TLorentzVector& p1, TLorentzVector& p2, TH1F* lead_jet_pdf, TH1F* mass_pdf);
}

#endif