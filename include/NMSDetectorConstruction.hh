/*
 * ONMS - Open Neutron Multiplicity Simulation
 *
 *
 * Copyright (C) 2013-2016 Moritz Kütt
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact: moritz@nuclearfreesoftware.org
 */

#ifndef NMSDetectorConstruction_h
#define NMSDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4ThreeVector.hh"
#include "G4GDMLParser.hh"
#include "G4SystemOfUnits.hh"
#include "G4Material.hh"

extern const G4String LVNAME_DETECTOR_CAVITY;
extern const G4String LVNAME_SAMPLE_MOTHER;
extern const G4String GDML_SAMPLE_POSITION;

class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;

class NMSDetectorConstruction : public G4VUserDetectorConstruction {
public:
  NMSDetectorConstruction(G4String detector, G4String sample);
  ~NMSDetectorConstruction();

  G4VPhysicalVolume* Construct();

private:
  G4GDMLParser detectorparser;
  G4GDMLParser sampleparser;
  G4String detectorfilename;
  G4String samplefilename;
  G4ThreeVector sampleposition;
};


#endif
