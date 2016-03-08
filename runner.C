
P2016 btof BEmcChkStat CorrX OSpaceZ2 OGridLeak3D NoHistos NoRunco -tags -geantOut -evout

// /star/data03/daq/jdb/run16_auau200/vpd_slew/st_physics_17035160_raw_5500003.daq

{

	// Load the shared libs
	gROOT->Macro("Load.C");

	Info(__FILE__, "Enabling Logger...");
	gROOT->LoadMacro("LoadLogger.C");
	LoadLogger();

	// if (gROOT->IsBatch()) {
	// 	gSystem->Load("libGui.so");
	// 	gSystem->Load("libGQt.so");
	// }

	
	gSystem->Load("StDbLib");
	gSystem->Load("StDbBroker");
	gSystem->Load("St_db_Maker");

	if ( gSystem->Load("StDbUtilities") > 0 )
	gSystem->Load("StDbUtilities");

	gSystem->Load("RTS");
	gSystem->Load("StEvent");
	gSystem->Load("StDaqLib"); 
	gSystem->Load("StDetectorDbMaker");
	gSystem->Load("StMagF");
	gSystem->Load("StDAQMaker"); 
	// gSystem->Load("libStTpcDb");
	// gSystem->Load("libStTriggerDataMaker");
	// gSystem->Load("libStEventMaker");


	gSystem->Load("StTriggerDataMaker");
	gSystem->Load("StEventMaker");

	gSystem->Load("StIOMaker");
	gSystem->Load("St_pp2pp_Maker");

	gROOT->LoadMacro("$STAR/StRoot/StMuDSTMaker/COMMON/macros/loadSharedLibraries.C");
	loadSharedLibraries();
	

	// Create Chain
	chain = new StBFChain(); 
	cout << "Create chain " << chain->GetName() << endl;

	chain->SetFlags( "P2016 btof BEmcChkStat CorrX OSpaceZ2 OGridLeak3D" );
	chain->Set_IO_Files("/star/data03/daq/jdb/run16_auau200/vpd_slew/st_physics_17035160_raw_5500003.daq", "out");
	


	Int_t evt_count = 0 ; 
	 while ( chain->MakeEvent() == kStOK && evt_count < 2 ) { 
	 	evt_count++;
	 }
  
	cout << "No. of events run " << evt_count << endl ;

	chain->Finish();  // close chain


	delete chain;
}