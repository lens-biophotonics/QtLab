int32 __CFUNC     DAQmxAddGlobalChansToTask      (TaskHandle taskHandle, const char channelNames[]) {return 0;}
int32 __CFUNC     DAQmxStartTask                 (TaskHandle taskHandle) {return 0;}
int32 __CFUNC     DAQmxStopTask                  (TaskHandle taskHandle) {return 0;}
int32 __CFUNC     DAQmxClearTask                 (TaskHandle taskHandle) {return 0;}
int32 __CFUNC     DAQmxWaitUntilTaskDone         (TaskHandle taskHandle, float64 timeToWait) {return 0;}
int32 __CFUNC     DAQmxWaitForValidTimestamp     (TaskHandle taskHandle, int32 timestampEvent, float64 timeout, CVIAbsoluteTime* timestamp) {return 0;}
int32 __CFUNC     DAQmxIsTaskDone                (TaskHandle taskHandle, bool32 *isTaskDone) {return 0;}
int32 __CFUNC     DAQmxTaskControl               (TaskHandle taskHandle, int32 action) {return 0;}
int32 __CFUNC     DAQmxGetNthTaskChannel         (TaskHandle taskHandle, uInt32 index, char buffer[], int32 bufferSize) {return 0;}
int32 __CFUNC     DAQmxGetNthTaskDevice          (TaskHandle taskHandle, uInt32 index, char buffer[], int32 bufferSize) {return 0;}
int32 __CFUNC_C   DAQmxGetTaskAttribute          (TaskHandle taskHandle, int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC     DAQmxCreateAIVoltageChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAICurrentChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, int32 shuntResistorLoc, float64 extShuntResistorVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIVoltageRMSChan    (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAICurrentRMSChan    (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, int32 shuntResistorLoc, float64 extShuntResistorVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIThrmcplChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 thermocoupleType, int32 cjcSource, float64 cjcVal, const char cjcChannel[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIRTDChan           (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 rtdType, int32 resistanceConfig, int32 currentExcitSource, float64 currentExcitVal, float64 r0) {return 0;}
int32 __CFUNC     DAQmxCreateAIThrmstrChanIex    (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 resistanceConfig, int32 currentExcitSource, float64 currentExcitVal, float64 a, float64 b, float64 c) {return 0;}
int32 __CFUNC     DAQmxCreateAIThrmstrChanVex    (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 resistanceConfig, int32 voltageExcitSource, float64 voltageExcitVal, float64 a, float64 b, float64 c, float64 r1) {return 0;}
int32 __CFUNC     DAQmxCreateAIFreqVoltageChan   (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, float64 thresholdLevel, float64 hysteresis, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIResistanceChan    (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 resistanceConfig, int32 currentExcitSource, float64 currentExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIStrainGageChan    (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 strainConfig, int32 voltageExcitSource, float64 voltageExcitVal, float64 gageFactor, float64 initialBridgeVoltage, float64 nominalGageResistance, float64 poissonRatio, float64 leadWireResistance, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIRosetteStrainGageChan    (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 rosetteType, float64 gageOrientation, const int32 rosetteMeasTypes[], uInt32 numRosetteMeasTypes, int32 strainConfig, int32 voltageExcitSource, float64 voltageExcitVal,float64 gageFactor, float64 nominalGageResistance,float64 poissonRatio,float64 leadWireResistance) {return 0;}
int32 __CFUNC     DAQmxCreateAIForceBridgeTwoPointLinChan(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,float64 firstElectricalVal,float64 secondElectricalVal,int32	electricalUnits,float64 firstPhysicalVal,float64 secondPhysicalVal,int32 physicalUnits,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIForceBridgeTableChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,const float64 electricalVals[],uInt32 numElectricalVals,int32	electricalUnits,const float64 physicalVals[],uInt32 numPhysicalVals,int32 physicalUnits,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIForceBridgePolynomialChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,const float64 forwardCoeffs[],uInt32 numForwardCoeffs,const float64 reverseCoeffs[],uInt32 numReverseCoeffs,int32	electricalUnits,int32 physicalUnits,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIPressureBridgeTwoPointLinChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,float64 firstElectricalVal,float64 secondElectricalVal,int32	electricalUnits,float64 firstPhysicalVal,float64 secondPhysicalVal,int32 physicalUnits,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIPressureBridgeTableChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,const float64 electricalVals[],uInt32 numElectricalVals,int32	electricalUnits,const float64 physicalVals[],uInt32 numPhysicalVals,int32 physicalUnits,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIPressureBridgePolynomialChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,const float64 forwardCoeffs[],uInt32 numForwardCoeffs,const float64 reverseCoeffs[],uInt32 numReverseCoeffs,int32	electricalUnits,int32 physicalUnits,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAITorqueBridgeTwoPointLinChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,float64 firstElectricalVal,float64 secondElectricalVal,int32	electricalUnits,float64 firstPhysicalVal,float64 secondPhysicalVal,int32 physicalUnits,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAITorqueBridgeTableChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,const float64 electricalVals[],uInt32 numElectricalVals,int32	electricalUnits,const float64 physicalVals[],uInt32 numPhysicalVals,int32 physicalUnits,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAITorqueBridgePolynomialChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,const float64 forwardCoeffs[],uInt32 numForwardCoeffs,const float64 reverseCoeffs[],uInt32 numReverseCoeffs,int32	electricalUnits,int32 physicalUnits,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIBridgeChan    (TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 bridgeConfig,int32 voltageExcitSource,float64 voltageExcitVal,float64 nominalBridgeResistance,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIVoltageChanWithExcit(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, int32 bridgeConfig, int32 voltageExcitSource, float64 voltageExcitVal, bool32 useExcitForScaling, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAITempBuiltInSensorChan(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 units) {return 0;}
int32 __CFUNC     DAQmxCreateAIAccelChan         (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, float64 sensitivity, int32 sensitivityUnits, int32 currentExcitSource, float64 currentExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIVelocityIEPEChan  (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, float64 sensitivity, int32 sensitivityUnits, int32 currentExcitSource, float64 currentExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIForceIEPEChan         (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, float64 sensitivity, int32 sensitivityUnits, int32 currentExcitSource, float64 currentExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIMicrophoneChan    (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, int32 units, float64 micSensitivity, float64 maxSndPressLevel, int32 currentExcitSource, float64 currentExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIChargeChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIAccelChargeChan  (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, float64 sensitivity, int32 sensitivityUnits, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIAccel4WireDCVoltageChan  (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, float64 sensitivity, int32 sensitivityUnits, int32 voltageExcitSource, float64 voltageExcitVal, bool32 useExcitForScaling, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIPosLVDTChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, float64 sensitivity, int32 sensitivityUnits, int32 voltageExcitSource, float64 voltageExcitVal, float64 voltageExcitFreq, int32 ACExcitWireMode, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIPosRVDTChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, float64 sensitivity, int32 sensitivityUnits, int32 voltageExcitSource, float64 voltageExcitVal, float64 voltageExcitFreq, int32 ACExcitWireMode, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIPosEddyCurrProxProbeChan(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, float64 sensitivity, int32 sensitivityUnits, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAIDeviceTempChan    (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 units) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIVoltageChan   (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAICurrentChan   (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, int32 shuntResistorLoc, float64 extShuntResistorVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIThrmcplChan   (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 cjcSource, float64 cjcVal, const char cjcChannel[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIRTDChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 resistanceConfig, int32 currentExcitSource, float64 currentExcitVal) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIThrmstrChanIex(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 resistanceConfig, int32 currentExcitSource, float64 currentExcitVal) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIThrmstrChanVex(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 resistanceConfig, int32 voltageExcitSource, float64 voltageExcitVal, float64 r1) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIResistanceChan(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 resistanceConfig, int32 currentExcitSource, float64 currentExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIStrainGageChan(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 voltageExcitSource, float64 voltageExcitVal, float64 initialBridgeVoltage, float64 leadWireResistance, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIForceBridgeChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 voltageExcitSource,float64 voltageExcitVal,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIPressureBridgeChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 voltageExcitSource,float64 voltageExcitVal,	const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAITorqueBridgeChan(TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 voltageExcitSource,float64 voltageExcitVal,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIBridgeChan    (TaskHandle taskHandle,const char physicalChannel[],const char nameToAssignToChannel[],float64 minVal,float64 maxVal,int32 units,int32 voltageExcitSource,float64 voltageExcitVal,const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIVoltageChanWithExcit(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, int32 voltageExcitSource, float64 voltageExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIAccelChan     (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, int32 currentExcitSource, float64 currentExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIForceIEPEChan     (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, int32 currentExcitSource, float64 currentExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIMicrophoneChan(TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, int32 units, float64 maxSndPressLevel, int32 currentExcitSource, float64 currentExcitVal, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIPosLVDTChan   (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 voltageExcitSource, float64 voltageExcitVal, float64 voltageExcitFreq, int32 ACExcitWireMode, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateTEDSAIPosRVDTChan   (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 voltageExcitSource, float64 voltageExcitVal, float64 voltageExcitFreq, int32 ACExcitWireMode, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAOVoltageChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAOCurrentChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateAOFuncGenChan       (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 type, float64 freq, float64 amplitude, float64 offset) {return 0;}
int32 __CFUNC     DAQmxCreateDIChan              (TaskHandle taskHandle, const char lines[], const char nameToAssignToLines[], int32 lineGrouping) {return 0;}
int32 __CFUNC     DAQmxCreateDOChan              (TaskHandle taskHandle, const char lines[], const char nameToAssignToLines[], int32 lineGrouping) {return 0;}
int32 __CFUNC     DAQmxCreateCIFreqChan          (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 edge, int32 measMethod, float64 measTime, uInt32 divisor, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCIPeriodChan        (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 edge, int32 measMethod, float64 measTime, uInt32 divisor, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCICountEdgesChan    (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], int32 edge, uInt32 initialCount, int32 countDirection) {return 0;}
int32 __CFUNC     DAQmxCreateCIDutyCycleChan     (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minFreq, float64 maxFreq, int32 edge, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCIPulseWidthChan    (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 startingEdge, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCISemiPeriodChan    (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCITwoEdgeSepChan       (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, int32 firstEdge, int32 secondEdge, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCIPulseChanFreq        (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units) {return 0;}
int32 __CFUNC     DAQmxCreateCIPulseChanTime        (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units) {return 0;}
int32 __CFUNC     DAQmxCreateCIPulseChanTicks       (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], const char sourceTerminal[], float64 minVal, float64 maxVal) {return 0;}
int32 __CFUNC     DAQmxCreateCILinEncoderChan    (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], int32 decodingType, bool32 ZidxEnable, float64 ZidxVal, int32 ZidxPhase, int32 units, float64 distPerPulse, float64 initialPos, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCIAngEncoderChan    (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], int32 decodingType, bool32 ZidxEnable, float64 ZidxVal, int32 ZidxPhase, int32 units, uInt32 pulsesPerRev, float64 initialAngle, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCILinVelocityChan  (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 decodingType, int32 units, float64 distPerPulse, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCIAngVelocityChan  (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 decodingType, int32 units, uInt32 pulsesPerRev, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCIGPSTimestampChan  (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], int32 units, int32 syncMethod, const char customScaleName[]) {return 0;}
int32 __CFUNC     DAQmxCreateCOPulseChanFreq     (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], int32 units, int32 idleState, float64 initialDelay, float64 freq, float64 dutyCycle) {return 0;}
int32 __CFUNC     DAQmxCreateCOPulseChanTime     (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], int32 units, int32 idleState, float64 initialDelay, float64 lowTime, float64 highTime) {return 0;}
int32 __CFUNC     DAQmxCreateCOPulseChanTicks    (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[], const char sourceTerminal[], int32 idleState, int32 initialDelay, int32 lowTicks, int32 highTicks) {return 0;}
int32 __CFUNC     DAQmxGetAIChanCalCalDate       (TaskHandle taskHandle, const char channelName[], uInt32 *year, uInt32 *month, uInt32 *day, uInt32 *hour, uInt32 *minute) {return 0;}
int32 __CFUNC     DAQmxSetAIChanCalCalDate       (TaskHandle taskHandle, const char channelName[], uInt32 year, uInt32 month, uInt32 day, uInt32 hour, uInt32 minute) {return 0;}
int32 __CFUNC     DAQmxGetAIChanCalExpDate       (TaskHandle taskHandle, const char channelName[], uInt32 *year, uInt32 *month, uInt32 *day, uInt32 *hour, uInt32 *minute) {return 0;}
int32 __CFUNC     DAQmxSetAIChanCalExpDate       (TaskHandle taskHandle, const char channelName[], uInt32 year, uInt32 month, uInt32 day, uInt32 hour, uInt32 minute) {return 0;}
int32 __CFUNC_C   DAQmxGetChanAttribute          (TaskHandle taskHandle, const char channel[], int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC_C   DAQmxSetChanAttribute          (TaskHandle taskHandle, const char channel[], int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetChanAttribute        (TaskHandle taskHandle, const char channel[], int32 attribute) {return 0;}
int32 __CFUNC     DAQmxCfgSampClkTiming          (TaskHandle taskHandle, const char source[], float64 rate, int32 activeEdge, int32 sampleMode, uInt64 sampsPerChan) {return 0;}
int32 __CFUNC     DAQmxCfgHandshakingTiming      (TaskHandle taskHandle, int32 sampleMode, uInt64 sampsPerChan) {return 0;}
int32 __CFUNC     DAQmxCfgBurstHandshakingTimingImportClock(TaskHandle taskHandle, int32 sampleMode, uInt64 sampsPerChan, float64 sampleClkRate, const char sampleClkSrc[], int32 sampleClkActiveEdge, int32 pauseWhen, int32 readyEventActiveLevel) {return 0;}
int32 __CFUNC     DAQmxCfgBurstHandshakingTimingExportClock(TaskHandle taskHandle, int32 sampleMode, uInt64 sampsPerChan, float64 sampleClkRate, const char sampleClkOutpTerm[], int32 sampleClkPulsePolarity, int32 pauseWhen, int32 readyEventActiveLevel) {return 0;}
int32 __CFUNC     DAQmxCfgChangeDetectionTiming  (TaskHandle taskHandle, const char risingEdgeChan[], const char fallingEdgeChan[], int32 sampleMode, uInt64 sampsPerChan) {return 0;}
int32 __CFUNC     DAQmxCfgImplicitTiming         (TaskHandle taskHandle, int32 sampleMode, uInt64 sampsPerChan) {return 0;}
int32 __CFUNC     DAQmxCfgPipelinedSampClkTiming (TaskHandle taskHandle, const char source[], float64 rate, int32 activeEdge, int32 sampleMode, uInt64 sampsPerChan) {return 0;}
int32 __CFUNC_C   DAQmxGetTimingAttribute        (TaskHandle taskHandle, int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC_C   DAQmxSetTimingAttribute        (TaskHandle taskHandle, int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetTimingAttribute      (TaskHandle taskHandle, int32 attribute) {return 0;}
int32 __CFUNC_C   DAQmxGetTimingAttributeEx      (TaskHandle taskHandle, const char deviceNames[], int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC_C   DAQmxSetTimingAttributeEx      (TaskHandle taskHandle, const char deviceNames[], int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetTimingAttributeEx    (TaskHandle taskHandle, const char deviceNames[], int32 attribute) {return 0;}
int32 __CFUNC     DAQmxDisableStartTrig          (TaskHandle taskHandle) {return 0;}
int32 __CFUNC     DAQmxCfgDigEdgeStartTrig       (TaskHandle taskHandle, const char triggerSource[], int32 triggerEdge) {return 0;}
int32 __CFUNC     DAQmxCfgAnlgEdgeStartTrig      (TaskHandle taskHandle, const char triggerSource[], int32 triggerSlope, float64 triggerLevel) {return 0;}
int32 __CFUNC     DAQmxCfgAnlgMultiEdgeStartTrig (TaskHandle taskHandle, const char triggerSources[], int32 triggerSlopeArray[], float64 triggerLevelArray[], uInt32 arraySize) {return 0;}
int32 __CFUNC     DAQmxCfgAnlgWindowStartTrig    (TaskHandle taskHandle, const char triggerSource[], int32 triggerWhen, float64 windowTop, float64 windowBottom) {return 0;}
int32 __CFUNC     DAQmxCfgTimeStartTrig          (TaskHandle taskHandle, CVIAbsoluteTime when, int32 timescale) {return 0;}
int32 __CFUNC     DAQmxCfgDigPatternStartTrig    (TaskHandle taskHandle, const char triggerSource[], const char triggerPattern[], int32 triggerWhen) {return 0;}
int32 __CFUNC     DAQmxDisableRefTrig            (TaskHandle taskHandle) {return 0;}
int32 __CFUNC     DAQmxCfgDigEdgeRefTrig         (TaskHandle taskHandle, const char triggerSource[], int32 triggerEdge, uInt32 pretriggerSamples) {return 0;}
int32 __CFUNC     DAQmxCfgAnlgEdgeRefTrig        (TaskHandle taskHandle, const char triggerSource[], int32 triggerSlope, float64 triggerLevel, uInt32 pretriggerSamples) {return 0;}
int32 __CFUNC     DAQmxCfgAnlgMultiEdgeRefTrig   (TaskHandle taskHandle, const char triggerSources[], int32 triggerSlopeArray[], float64 triggerLevelArray[], uInt32 pretriggerSamples, uInt32 arraySize) {return 0;}
int32 __CFUNC     DAQmxCfgAnlgWindowRefTrig      (TaskHandle taskHandle, const char triggerSource[], int32 triggerWhen, float64 windowTop, float64 windowBottom, uInt32 pretriggerSamples) {return 0;}
int32 __CFUNC     DAQmxCfgDigPatternRefTrig      (TaskHandle taskHandle, const char triggerSource[], const char triggerPattern[], int32 triggerWhen, uInt32 pretriggerSamples) {return 0;}
int32 __CFUNC_C   DAQmxGetTrigAttribute          (TaskHandle taskHandle, int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC_C   DAQmxSetTrigAttribute          (TaskHandle taskHandle, int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetTrigAttribute        (TaskHandle taskHandle, int32 attribute) {return 0;}
int32 __CFUNC     DAQmxReadAnalogF64             (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadAnalogScalarF64       (TaskHandle taskHandle, float64 timeout, float64 *value, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadBinaryI16             (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, int16 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadBinaryU16             (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, uInt16 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadBinaryI32             (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, int32 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadBinaryU32             (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadDigitalU8             (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, uInt8 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadDigitalU16            (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, uInt16 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadDigitalU32            (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadDigitalScalarU32      (TaskHandle taskHandle, float64 timeout, uInt32 *value, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadDigitalLines          (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, uInt8 readArray[], uInt32 arraySizeInBytes, int32 *sampsPerChanRead, int32 *numBytesPerSamp, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCounterF64            (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, float64 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCounterU32            (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, uInt32 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCounterF64Ex          (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCounterU32Ex          (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCounterScalarF64      (TaskHandle taskHandle, float64 timeout, float64 *value, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCounterScalarU32      (TaskHandle taskHandle, float64 timeout, uInt32 *value, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCtrFreq               (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 interleaved, float64 readArrayFrequency[], float64 readArrayDutyCycle[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCtrTime               (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 interleaved, float64 readArrayHighTime[], float64 readArrayLowTime[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCtrTicks              (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 interleaved, uInt32 readArrayHighTicks[], uInt32 readArrayLowTicks[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCtrFreqScalar         (TaskHandle taskHandle, float64 timeout, float64 *frequency, float64 *dutyCycle, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCtrTimeScalar         (TaskHandle taskHandle, float64 timeout, float64 *highTime, float64 *lowTime, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadCtrTicksScalar        (TaskHandle taskHandle, float64 timeout, uInt32 *highTicks, uInt32 *lowTicks, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxReadRaw                   (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, void *readArray, uInt32 arraySizeInBytes, int32 *sampsRead, int32 *numBytesPerSamp, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxGetNthTaskReadChannel     (TaskHandle taskHandle, uInt32 index, char buffer[], int32 bufferSize) {return 0;}
int32 __CFUNC_C   DAQmxGetReadAttribute          (TaskHandle taskHandle, int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC_C   DAQmxSetReadAttribute          (TaskHandle taskHandle, int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetReadAttribute        (TaskHandle taskHandle, int32 attribute) {return 0;}
int32 __CFUNC     DAQmxConfigureLogging          (TaskHandle taskHandle, const char filePath[], int32 loggingMode, const char groupName[], int32 operation) {return 0;}
int32 __CFUNC     DAQmxStartNewFile              (TaskHandle taskHandle, const char filePath[]) {return 0;}
int32 __CFUNC     DAQmxWriteAnalogF64            (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const float64 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteAnalogScalarF64      (TaskHandle taskHandle, bool32 autoStart, float64 timeout, float64 value, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteBinaryI16            (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const int16 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteBinaryU16            (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const uInt16 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteBinaryI32            (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const int32 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteBinaryU32            (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const uInt32 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteDigitalU8            (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const uInt8 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteDigitalU16           (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const uInt16 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteDigitalU32           (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const uInt32 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteDigitalScalarU32     (TaskHandle taskHandle, bool32 autoStart, float64 timeout, uInt32 value, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteDigitalLines         (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const uInt8 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteCtrFreq              (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const float64 frequency[], const float64 dutyCycle[], int32 *numSampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteCtrFreqScalar        (TaskHandle taskHandle, bool32 autoStart, float64 timeout, float64 frequency, float64 dutyCycle, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteCtrTime              (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const float64 highTime[], const float64 lowTime[], int32 *numSampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteCtrTimeScalar        (TaskHandle taskHandle, bool32 autoStart, float64 timeout, float64 highTime, float64 lowTime, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteCtrTicks             (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const uInt32 highTicks[], const uInt32 lowTicks[], int32 *numSampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteCtrTicksScalar       (TaskHandle taskHandle, bool32 autoStart, float64 timeout, uInt32 highTicks, uInt32 lowTicks, bool32 *reserved) {return 0;}
int32 __CFUNC     DAQmxWriteRaw                  (TaskHandle taskHandle, int32 numSamps, bool32 autoStart, float64 timeout, const void *writeArray, int32 *sampsPerChanWritten, bool32 *reserved) {return 0;}
int32 __CFUNC_C   DAQmxGetWriteAttribute         (TaskHandle taskHandle, int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC_C   DAQmxSetWriteAttribute         (TaskHandle taskHandle, int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetWriteAttribute       (TaskHandle taskHandle, int32 attribute) {return 0;}
int32 __CFUNC     DAQmxExportSignal              (TaskHandle taskHandle, int32 signalID, const char outputTerminal[]) {return 0;}
int32 __CFUNC_C   DAQmxGetExportedSignalAttribute(TaskHandle taskHandle, int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC_C   DAQmxSetExportedSignalAttribute(TaskHandle taskHandle, int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetExportedSignalAttribute(TaskHandle taskHandle, int32 attribute) {return 0;}
int32 __CFUNC     DAQmxCfgInputBuffer            (TaskHandle taskHandle, uInt32 numSampsPerChan) {return 0;}
int32 __CFUNC     DAQmxCfgOutputBuffer           (TaskHandle taskHandle, uInt32 numSampsPerChan) {return 0;}
int32 __CFUNC_C   DAQmxGetBufferAttribute        (TaskHandle taskHandle, int32 attribute, void *value) {return 0;}
int32 __CFUNC_C   DAQmxSetBufferAttribute        (TaskHandle taskHandle, int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetBufferAttribute      (TaskHandle taskHandle, int32 attribute) {return 0;}
int32 __CFUNC_C   DAQmxGetSwitchScanAttribute    (TaskHandle taskHandle, int32 attribute, void *value) {return 0;}
int32 __CFUNC_C   DAQmxSetSwitchScanAttribute    (TaskHandle taskHandle, int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetSwitchScanAttribute  (TaskHandle taskHandle, int32 attribute) {return 0;}
int32 __CFUNC     DAQmxDisableAdvTrig            (TaskHandle taskHandle) {return 0;}
int32 __CFUNC     DAQmxCfgDigEdgeAdvTrig         (TaskHandle taskHandle, const char triggerSource[], int32 triggerEdge) {return 0;}
int32 __CFUNC     DAQmxSendSoftwareTrigger       (TaskHandle taskHandle, int32 triggerID) {return 0;}
int32 __CFUNC     DAQmxControlWatchdogTask       (TaskHandle taskHandle, int32 action) {return 0;}
int32 __CFUNC DAQmxCfgWatchdogAOExpirStates(TaskHandle taskHandle, const char channelNames[], const float64 expirStateArray[], const int32 outputTypeArray[], uInt32 arraySize) {return 0;}
int32 __CFUNC DAQmxCfgWatchdogCOExpirStates(TaskHandle taskHandle, const char channelNames[], const int32 expirStateArray[], uInt32 arraySize) {return 0;}
int32 __CFUNC DAQmxCfgWatchdogDOExpirStates(TaskHandle taskHandle, const char channelNames[], const int32 expirStateArray[], uInt32 arraySize) {return 0;}
int32 __CFUNC_C   DAQmxGetWatchdogAttribute      (TaskHandle taskHandle, const char lines[], int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC_C   DAQmxSetWatchdogAttribute      (TaskHandle taskHandle, const char lines[], int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetWatchdogAttribute    (TaskHandle taskHandle, const char lines[], int32 attribute) {return 0;}
int32 __CFUNC     DAQmxPerformBridgeOffsetNullingCal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC     DAQmxPerformBridgeOffsetNullingCalEx(TaskHandle taskHandle, const char channel[], bool32 skipUnsupportedChannels) {return 0;}
int32 __CFUNC     DAQmxPerformThrmcplLeadOffsetNullingCal(TaskHandle taskHandle, const char channel[], bool32 skipUnsupportedChannels) {return 0;}
int32 __CFUNC     DAQmxPerformStrainShuntCal     (TaskHandle taskHandle, const char channel[], float64 shuntResistorValue, int32 shuntResistorLocation, bool32 skipUnsupportedChannels) {return 0;}
int32 __CFUNC     DAQmxPerformStrainShuntCalEx   (TaskHandle taskHandle, const char channel[], float64 shuntResistorValue, int32 shuntResistorLocation, int32 shuntResistorSelect, int32 shuntResistorSource, bool32 skipUnsupportedChannels) {return 0;}
int32 __CFUNC     DAQmxPerformBridgeShuntCal     (TaskHandle taskHandle, const char channel[], float64 shuntResistorValue, int32 shuntResistorLocation, float64 bridgeResistance, bool32 skipUnsupportedChannels) {return 0;}
int32 __CFUNC     DAQmxPerformBridgeShuntCalEx   (TaskHandle taskHandle, const char channel[], float64 shuntResistorValue, int32 shuntResistorLocation, int32 shuntResistorSelect, int32 shuntResistorSource, float64 bridgeResistance, bool32 skipUnsupportedChannels) {return 0;}
int32 __CFUNC     DAQmxWaitForNextSampleClock(TaskHandle taskHandle, float64 timeout, bool32 *isLate) {return 0;}
int32 __CFUNC_C   DAQmxGetRealTimeAttribute  (TaskHandle taskHandle, int32 attribute, void *value, ...) {return 0;}
int32 __CFUNC_C   DAQmxSetRealTimeAttribute  (TaskHandle taskHandle, int32 attribute, ...) {return 0;}
int32 __CFUNC     DAQmxResetRealTimeAttribute(TaskHandle taskHandle, int32 attribute) {return 0;}
int32 __CFUNC     DAQmxSaveTask                  (TaskHandle taskHandle, const char saveAs[], const char author[], uInt32 options) {return 0;}
int32 __CFUNC     DAQmxSaveGlobalChan            (TaskHandle taskHandle, const char channelName[], const char saveAs[], const char author[], uInt32 options) {return 0;}
int32 __CFUNC DAQmxGetBufInputBufSize(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetBufInputBufSize(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetBufInputBufSize(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetBufInputOnbrdBufSize(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetBufOutputBufSize(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetBufOutputBufSize(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetBufOutputBufSize(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetBufOutputOnbrdBufSize(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetBufOutputOnbrdBufSize(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetBufOutputOnbrdBufSize(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIMax(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIMax(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIMax(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIMin(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIMin(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIMin(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAICustomScaleName(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAICustomScaleName(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetAICustomScaleName(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIMeasType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetAIVoltageUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIVoltageUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIVoltageUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIVoltagedBRef(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIVoltagedBRef(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIVoltagedBRef(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIVoltageACRMSUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIVoltageACRMSUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIVoltageACRMSUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAITempUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAITempUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAITempUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIThrmcplType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIThrmcplType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIThrmcplType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIThrmcplScaleType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIThrmcplScaleType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIThrmcplScaleType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIThrmcplCJCSrc(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetAIThrmcplCJCVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIThrmcplCJCVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIThrmcplCJCVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIThrmcplCJCChan(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetAIRTDType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRTDType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIRTDType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRTDR0(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRTDR0(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIRTDR0(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRTDA(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRTDA(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIRTDA(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRTDB(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRTDB(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIRTDB(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRTDC(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRTDC(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIRTDC(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIThrmstrA(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIThrmstrA(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIThrmstrA(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIThrmstrB(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIThrmstrB(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIThrmstrB(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIThrmstrC(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIThrmstrC(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIThrmstrC(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIThrmstrR1(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIThrmstrR1(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIThrmstrR1(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIForceReadFromChan(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIForceReadFromChan(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIForceReadFromChan(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAICurrentUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAICurrentUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAICurrentUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAICurrentACRMSUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAICurrentACRMSUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAICurrentACRMSUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIStrainUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIStrainUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIStrainUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIStrainGageForceReadFromChan(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIStrainGageForceReadFromChan(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIStrainGageForceReadFromChan(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIStrainGageGageFactor(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIStrainGageGageFactor(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIStrainGageGageFactor(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIStrainGagePoissonRatio(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIStrainGagePoissonRatio(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIStrainGagePoissonRatio(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIStrainGageCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIStrainGageCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIStrainGageCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRosetteStrainGageRosetteType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetAIRosetteStrainGageOrientation(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRosetteStrainGageOrientation(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIRosetteStrainGageOrientation(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRosetteStrainGageStrainChans(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetAIRosetteStrainGageRosetteMeasType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRosetteStrainGageRosetteMeasType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIRosetteStrainGageRosetteMeasType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIResistanceUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIResistanceUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIResistanceUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIFreqUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIFreqUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIFreqUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIFreqThreshVoltage(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIFreqThreshVoltage(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIFreqThreshVoltage(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIFreqHyst(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIFreqHyst(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIFreqHyst(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILVDTUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAILVDTUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAILVDTUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILVDTSensitivity(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAILVDTSensitivity(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAILVDTSensitivity(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILVDTSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAILVDTSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAILVDTSensitivityUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRVDTUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRVDTUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIRVDTUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRVDTSensitivity(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRVDTSensitivity(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIRVDTSensitivity(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRVDTSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRVDTSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIRVDTSensitivityUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIEddyCurrentProxProbeUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIEddyCurrentProxProbeUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIEddyCurrentProxProbeUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIEddyCurrentProxProbeSensitivity(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIEddyCurrentProxProbeSensitivity(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIEddyCurrentProxProbeSensitivity(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIEddyCurrentProxProbeSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIEddyCurrentProxProbeSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIEddyCurrentProxProbeSensitivityUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAISoundPressureMaxSoundPressureLvl(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAISoundPressureMaxSoundPressureLvl(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAISoundPressureMaxSoundPressureLvl(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAISoundPressureUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAISoundPressureUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAISoundPressureUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAISoundPressuredBRef(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAISoundPressuredBRef(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAISoundPressuredBRef(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIMicrophoneSensitivity(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIMicrophoneSensitivity(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIMicrophoneSensitivity(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAccelUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAccelUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIAccelUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAcceldBRef(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAcceldBRef(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIAcceldBRef(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAccel4WireDCVoltageSensitivity(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAccel4WireDCVoltageSensitivity(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIAccel4WireDCVoltageSensitivity(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAccel4WireDCVoltageSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAccel4WireDCVoltageSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIAccel4WireDCVoltageSensitivityUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAccelSensitivity(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAccelSensitivity(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIAccelSensitivity(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAccelSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAccelSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIAccelSensitivityUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAccelChargeSensitivity(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAccelChargeSensitivity(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIAccelChargeSensitivity(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAccelChargeSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAccelChargeSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIAccelChargeSensitivityUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIVelocityUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIVelocityUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIVelocityUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIVelocityIEPESensordBRef(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIVelocityIEPESensordBRef(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIVelocityIEPESensordBRef(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIVelocityIEPESensorSensitivity(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIVelocityIEPESensorSensitivity(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIVelocityIEPESensorSensitivity(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIVelocityIEPESensorSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIVelocityIEPESensorSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIVelocityIEPESensorSensitivityUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIForceUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIForceUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIForceUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIForceIEPESensorSensitivity(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIForceIEPESensorSensitivity(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIForceIEPESensorSensitivity(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIForceIEPESensorSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIForceIEPESensorSensitivityUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIForceIEPESensorSensitivityUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIPressureUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIPressureUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIPressureUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAITorqueUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAITorqueUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAITorqueUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeElectricalUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeElectricalUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeElectricalUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgePhysicalUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgePhysicalUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgePhysicalUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeScaleType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeScaleType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeScaleType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeTwoPointLinFirstElectricalVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeTwoPointLinFirstElectricalVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeTwoPointLinFirstElectricalVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeTwoPointLinFirstPhysicalVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeTwoPointLinFirstPhysicalVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeTwoPointLinFirstPhysicalVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeTwoPointLinSecondElectricalVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeTwoPointLinSecondElectricalVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeTwoPointLinSecondElectricalVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeTwoPointLinSecondPhysicalVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeTwoPointLinSecondPhysicalVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeTwoPointLinSecondPhysicalVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeTableElectricalVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeTableElectricalVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeTableElectricalVals(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeTablePhysicalVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeTablePhysicalVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeTablePhysicalVals(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgePolyForwardCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIBridgePolyForwardCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIBridgePolyForwardCoeff(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgePolyReverseCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIBridgePolyReverseCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIBridgePolyReverseCoeff(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChargeUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIChargeUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIChargeUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIIsTEDS(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetAITEDSUnits(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetAICoupling(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAICoupling(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAICoupling(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIImpedance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIImpedance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIImpedance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAITermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAITermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAITermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIInputSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAIInputSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetAIInputSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIResistanceCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIResistanceCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIResistanceCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILeadWireResistance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAILeadWireResistance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAILeadWireResistance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeNomResistance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeNomResistance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeNomResistance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeInitialVoltage(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeInitialVoltage(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeInitialVoltage(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeInitialRatio(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeInitialRatio(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeInitialRatio(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeShuntCalEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeShuntCalEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeShuntCalEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeShuntCalSelect(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeShuntCalSelect(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeShuntCalSelect(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeShuntCalShuntCalASrc(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeShuntCalShuntCalASrc(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeShuntCalShuntCalASrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeShuntCalGainAdjust(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeShuntCalGainAdjust(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeShuntCalGainAdjust(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeShuntCalShuntCalAResistance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeShuntCalShuntCalAResistance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeShuntCalShuntCalAResistance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeShuntCalShuntCalAActualResistance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeShuntCalShuntCalAActualResistance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeShuntCalShuntCalAActualResistance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeShuntCalShuntCalBResistance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeShuntCalShuntCalBResistance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeShuntCalShuntCalBResistance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeShuntCalShuntCalBActualResistance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeShuntCalShuntCalBActualResistance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeShuntCalShuntCalBActualResistance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeBalanceCoarsePot(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeBalanceCoarsePot(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeBalanceCoarsePot(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIBridgeBalanceFinePot(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIBridgeBalanceFinePot(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIBridgeBalanceFinePot(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAICurrentShuntLoc(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAICurrentShuntLoc(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAICurrentShuntLoc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAICurrentShuntResistance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAICurrentShuntResistance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAICurrentShuntResistance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIExcitSense(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIExcitSense(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIExcitSense(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIExcitSrc(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIExcitSrc(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIExcitSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIExcitVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIExcitVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIExcitVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIExcitUseForScaling(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIExcitUseForScaling(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIExcitUseForScaling(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIExcitUseMultiplexed(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIExcitUseMultiplexed(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIExcitUseMultiplexed(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIExcitActualVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIExcitActualVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIExcitActualVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIExcitDCorAC(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIExcitDCorAC(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIExcitDCorAC(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIExcitVoltageOrCurrent(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIExcitVoltageOrCurrent(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIExcitVoltageOrCurrent(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIExcitIdleOutputBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIExcitIdleOutputBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIExcitIdleOutputBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIACExcitFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIACExcitFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIACExcitFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIACExcitSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIACExcitSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIACExcitSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIACExcitWireMode(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIACExcitWireMode(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIACExcitWireMode(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAISensorPowerVoltage(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAISensorPowerVoltage(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAISensorPowerVoltage(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAISensorPowerCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAISensorPowerCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAISensorPowerCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAISensorPowerType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAISensorPowerType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAISensorPowerType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIOpenThrmcplDetectEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIOpenThrmcplDetectEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIOpenThrmcplDetectEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIThrmcplLeadOffsetVoltage(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIThrmcplLeadOffsetVoltage(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIThrmcplLeadOffsetVoltage(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAtten(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAtten(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIAtten(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIProbeAtten(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIProbeAtten(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIProbeAtten(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILowpassEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAILowpassEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAILowpassEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILowpassCutoffFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAILowpassCutoffFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAILowpassCutoffFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILowpassSwitchCapClkSrc(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAILowpassSwitchCapClkSrc(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAILowpassSwitchCapClkSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILowpassSwitchCapExtClkFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAILowpassSwitchCapExtClkFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAILowpassSwitchCapExtClkFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILowpassSwitchCapExtClkDiv(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAILowpassSwitchCapExtClkDiv(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAILowpassSwitchCapExtClkDiv(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILowpassSwitchCapOutClkDiv(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAILowpassSwitchCapOutClkDiv(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAILowpassSwitchCapOutClkDiv(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrResponse(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrResponse(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrResponse(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrOrder(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrOrder(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrOrder(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrLowpassCutoffFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrLowpassCutoffFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrLowpassCutoffFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrHighpassCutoffFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrHighpassCutoffFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrHighpassCutoffFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrBandpassCenterFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrBandpassCenterFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrBandpassCenterFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrBandpassWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrBandpassWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrBandpassWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrNotchCenterFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrNotchCenterFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrNotchCenterFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrNotchWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrNotchWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrNotchWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDigFltrCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIDigFltrCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIDigFltrCoeff(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIFilterEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIFilterEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIFilterEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIFilterFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIFilterFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIFilterFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIFilterResponse(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIFilterResponse(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIFilterResponse(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIFilterOrder(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIFilterOrder(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAIFilterOrder(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIFilterDelay(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxGetAIFilterDelayUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIFilterDelayUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIFilterDelayUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRemoveFilterDelay(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRemoveFilterDelay(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIRemoveFilterDelay(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIFilterDelayAdjustment(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIFilterDelayAdjustment(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIFilterDelayAdjustment(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAveragingWinSize(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAveragingWinSize(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAIAveragingWinSize(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIResolutionUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetAIResolution(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxGetAIRawSampSize(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetAIRawSampJustification(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetAIADCTimingMode(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIADCTimingMode(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIADCTimingMode(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIADCCustomTimingMode(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIADCCustomTimingMode(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAIADCCustomTimingMode(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDitherEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDitherEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIDitherEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalHasValidCalInfo(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalEnableCal(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalEnableCal(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalEnableCal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalApplyCalIfExp(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalApplyCalIfExp(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalApplyCalIfExp(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalScaleType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalScaleType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalScaleType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalTablePreScaledVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalTablePreScaledVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalTablePreScaledVals(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalTableScaledVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalTableScaledVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalTableScaledVals(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalPolyForwardCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalPolyForwardCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalPolyForwardCoeff(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalPolyReverseCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalPolyReverseCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalPolyReverseCoeff(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalOperatorName(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalOperatorName(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalOperatorName(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalDesc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalDesc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalDesc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalVerifRefVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalVerifRefVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalVerifRefVals(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChanCalVerifAcqVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAIChanCalVerifAcqVals(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAIChanCalVerifAcqVals(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRngHigh(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRngHigh(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIRngHigh(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRngLow(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRngLow(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIRngLow(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDCOffset(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDCOffset(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIDCOffset(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIGain(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIGain(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIGain(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAISampAndHoldEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAISampAndHoldEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAISampAndHoldEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIAutoZeroMode(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIAutoZeroMode(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIAutoZeroMode(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIChopEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIChopEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIChopEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDataXferMaxRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDataXferMaxRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIDataXferMaxRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDataXferMech(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDataXferMech(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIDataXferMech(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDataXferReqCond(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDataXferReqCond(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIDataXferReqCond(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDataXferCustomThreshold(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIDataXferCustomThreshold(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAIDataXferCustomThreshold(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAIUsbXferReqSize(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAIUsbXferReqCount(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIMemMapEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIRawDataCompressionType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIRawDataCompressionType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIRawDataCompressionType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAILossyLSBRemovalCompressedSampSize(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAILossyLSBRemovalCompressedSampSize(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAILossyLSBRemovalCompressedSampSize(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIDevScalingCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxGetAIEnhancedAliasRejectionEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIEnhancedAliasRejectionEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIEnhancedAliasRejectionEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIOpenChanDetectEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIOpenChanDetectEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIOpenChanDetectEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIInputLimitsFaultDetectUpperLimit(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIInputLimitsFaultDetectUpperLimit(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIInputLimitsFaultDetectUpperLimit(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIInputLimitsFaultDetectLowerLimit(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIInputLimitsFaultDetectLowerLimit(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIInputLimitsFaultDetectLowerLimit(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIInputLimitsFaultDetectEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIInputLimitsFaultDetectEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIInputLimitsFaultDetectEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIPowerSupplyFaultDetectEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIPowerSupplyFaultDetectEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIPowerSupplyFaultDetectEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAIOvercurrentDetectEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIOvercurrentDetectEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIOvercurrentDetectEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOMax(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOMax(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOMax(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOMin(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOMin(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOMin(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOCustomScaleName(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAOCustomScaleName(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetAOCustomScaleName(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOOutputType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetAOVoltageUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOVoltageUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAOVoltageUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOVoltageCurrentLimit(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOVoltageCurrentLimit(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOVoltageCurrentLimit(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOCurrentUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOCurrentUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAOCurrentUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFuncGenType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFuncGenType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAOFuncGenType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFuncGenFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFuncGenFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOFuncGenFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFuncGenAmplitude(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFuncGenAmplitude(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOFuncGenAmplitude(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFuncGenOffset(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFuncGenOffset(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOFuncGenOffset(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFuncGenSquareDutyCycle(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFuncGenSquareDutyCycle(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOFuncGenSquareDutyCycle(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFuncGenModulationType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFuncGenModulationType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAOFuncGenModulationType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFuncGenFMDeviation(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFuncGenFMDeviation(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOFuncGenFMDeviation(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOOutputImpedance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOOutputImpedance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOOutputImpedance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOLoadImpedance(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOLoadImpedance(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOLoadImpedance(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOIdleOutputBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOIdleOutputBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAOIdleOutputBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAOTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOResolutionUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOResolutionUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAOResolutionUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOResolution(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxGetAODACRngHigh(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAODACRngHigh(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAODACRngHigh(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODACRngLow(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAODACRngLow(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAODACRngLow(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODACRefConnToGnd(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAODACRefConnToGnd(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAODACRefConnToGnd(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODACRefAllowConnToGnd(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAODACRefAllowConnToGnd(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAODACRefAllowConnToGnd(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODACRefSrc(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAODACRefSrc(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAODACRefSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODACRefExtSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAODACRefExtSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetAODACRefExtSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODACRefVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAODACRefVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAODACRefVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODACOffsetSrc(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAODACOffsetSrc(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAODACOffsetSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODACOffsetExtSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAODACOffsetExtSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetAODACOffsetExtSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODACOffsetVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAODACOffsetVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAODACOffsetVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOReglitchEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOReglitchEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAOReglitchEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFilterDelay(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFilterDelay(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOFilterDelay(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFilterDelayUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFilterDelayUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAOFilterDelayUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOFilterDelayAdjustment(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOFilterDelayAdjustment(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOFilterDelayAdjustment(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOGain(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAOGain(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAOGain(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOUseOnlyOnBrdMem(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOUseOnlyOnBrdMem(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAOUseOnlyOnBrdMem(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODataXferMech(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAODataXferMech(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAODataXferMech(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODataXferReqCond(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAODataXferReqCond(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAODataXferReqCond(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAOUsbXferReqSize(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAOUsbXferReqCount(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAOMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAOMemMapEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetAODevScalingCoeff(TaskHandle taskHandle, const char channel[], float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxGetAOEnhancedImageRejectionEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAOEnhancedImageRejectionEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAOEnhancedImageRejectionEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIInvertLines(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIInvertLines(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDIInvertLines(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDINumLines(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetDIDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDIDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDIDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetDIDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIDigFltrEnableBusMode(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIDigFltrEnableBusMode(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDIDigFltrEnableBusMode(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDIDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetDIDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDIDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetDIDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDIDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDITristate(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDITristate(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDITristate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDILogicFamily(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDILogicFamily(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDILogicFamily(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIDataXferMech(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIDataXferMech(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDIDataXferMech(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIDataXferReqCond(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIDataXferReqCond(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDIDataXferReqCond(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetDIUsbXferReqSize(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetDIUsbXferReqCount(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDIMemMapEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDIAcquireOn(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDIAcquireOn(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDIAcquireOn(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOOutputDriveType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOOutputDriveType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDOOutputDriveType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOInvertLines(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOInvertLines(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDOInvertLines(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDONumLines(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetDOTristate(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOTristate(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDOTristate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOLineStatesStartState(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOLineStatesStartState(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDOLineStatesStartState(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOLineStatesPausedState(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOLineStatesPausedState(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDOLineStatesPausedState(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOLineStatesDoneState(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOLineStatesDoneState(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDOLineStatesDoneState(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOLogicFamily(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOLogicFamily(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDOLogicFamily(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOOvercurrentLimit(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDOOvercurrentLimit(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetDOOvercurrentLimit(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOOvercurrentAutoReenable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOOvercurrentAutoReenable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDOOvercurrentAutoReenable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOOvercurrentReenablePeriod(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDOOvercurrentReenablePeriod(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetDOOvercurrentReenablePeriod(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOUseOnlyOnBrdMem(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOUseOnlyOnBrdMem(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDOUseOnlyOnBrdMem(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDODataXferMech(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDODataXferMech(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDODataXferMech(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDODataXferReqCond(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDODataXferReqCond(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDODataXferReqCond(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetDOUsbXferReqSize(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetDOUsbXferReqCount(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDOMemMapEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetDOGenerateOn(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDOGenerateOn(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDOGenerateOn(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIMax(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIMax(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIMax(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIMin(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIMin(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIMin(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICustomScaleName(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICustomScaleName(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICustomScaleName(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIMeasType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetCIFreqUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIFreqTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIFreqDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqStartingEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqStartingEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqStartingEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqMeasMeth(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqMeasMeth(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqMeasMeth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqEnableAveraging(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqEnableAveraging(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqEnableAveraging(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqMeasTime(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqMeasTime(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqMeasTime(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIFreqDiv(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIFreqDiv(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCIFreqDiv(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodStartingEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodStartingEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodStartingEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodMeasMeth(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodMeasMeth(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodMeasMeth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodEnableAveraging(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodEnableAveraging(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodEnableAveraging(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodMeasTime(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodMeasTime(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodMeasTime(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPeriodDiv(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPeriodDiv(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPeriodDiv(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesDir(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesDir(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesDir(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesDirTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesDirTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesDirTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountDirTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountDirTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountDirTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountDirLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountDirLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountDirLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountDirDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountDirDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountDirDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountDirDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountDirDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountDirDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountDirDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountDirDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountDirDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountDirDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountDirDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountDirDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountDirDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountDirDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountDirDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesInitialCnt(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesInitialCnt(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesInitialCnt(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesActiveEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesActiveEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesActiveEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetResetCount(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetResetCount(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetResetCount(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesCountResetActiveEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesCountResetActiveEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesCountResetActiveEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesGateEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesGateEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesGateEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesGateTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesGateTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesGateTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesGateTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesGateTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesGateTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesGateLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesGateLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesGateLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesGateDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesGateDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesGateDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesGateDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesGateDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesGateDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesGateDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesGateDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesGateDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesGateDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesGateDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesGateDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICountEdgesGateWhen(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICountEdgesGateWhen(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICountEdgesGateWhen(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDutyCycleTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIDutyCycleTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIDutyCycleTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDutyCycleTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIDutyCycleTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIDutyCycleTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDutyCycleLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIDutyCycleLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIDutyCycleLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDutyCycleDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIDutyCycleDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIDutyCycleDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDutyCycleDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIDutyCycleDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIDutyCycleDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDutyCycleDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIDutyCycleDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIDutyCycleDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDutyCycleDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIDutyCycleDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIDutyCycleDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDutyCycleStartingEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIDutyCycleStartingEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIDutyCycleStartingEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIAngEncoderUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIAngEncoderUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIAngEncoderUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIAngEncoderPulsesPerRev(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIAngEncoderPulsesPerRev(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCIAngEncoderPulsesPerRev(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIAngEncoderInitialAngle(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIAngEncoderInitialAngle(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIAngEncoderInitialAngle(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCILinEncoderUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCILinEncoderUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCILinEncoderUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCILinEncoderDistPerPulse(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCILinEncoderDistPerPulse(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCILinEncoderDistPerPulse(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCILinEncoderInitialPos(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCILinEncoderInitialPos(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCILinEncoderInitialPos(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderDecodingType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderDecodingType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderDecodingType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderAInputTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderAInputTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderAInputTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderAInputTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderAInputTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderAInputTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderAInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderAInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderAInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderAInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderAInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderAInputDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderAInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderAInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderAInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderAInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderAInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderAInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderAInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderAInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderAInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderAInputDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderAInputDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderAInputDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderBInputTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderBInputTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderBInputTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderBInputTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderBInputTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderBInputTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderBInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderBInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderBInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderBInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderBInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderBInputDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderBInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderBInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderBInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderBInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderBInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderBInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderBInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderBInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderBInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderBInputDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderBInputDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderBInputDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZInputTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZInputTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZInputTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZInputTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZInputTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZInputTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZInputDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZInputDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZInputDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZInputDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZIndexEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZIndexEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZIndexEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZIndexVal(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZIndexVal(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZIndexVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIEncoderZIndexPhase(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIEncoderZIndexPhase(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIEncoderZIndexPhase(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseWidthStartingEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseWidthStartingEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseWidthStartingEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITimestampUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITimestampUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCITimestampUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITimestampInitialSeconds(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITimestampInitialSeconds(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCITimestampInitialSeconds(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIGPSSyncMethod(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIGPSSyncMethod(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIGPSSyncMethod(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIGPSSyncSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIGPSSyncSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIGPSSyncSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityAngEncoderUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityAngEncoderUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityAngEncoderUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityAngEncoderPulsesPerRev(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityAngEncoderPulsesPerRev(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityAngEncoderPulsesPerRev(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityLinEncoderUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityLinEncoderUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityLinEncoderUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityLinEncoderDistPerPulse(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityLinEncoderDistPerPulse(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityLinEncoderDistPerPulse(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderDecodingType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderDecodingType(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderDecodingType(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderAInputTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderAInputTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderAInputTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderAInputTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderAInputTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderAInputTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderAInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderAInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderAInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderAInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderAInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderAInputDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderAInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderAInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderAInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderAInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderAInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderAInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderAInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderAInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderAInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderBInputTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderBInputTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderBInputTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderBInputTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderBInputTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderBInputTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderBInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderBInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderBInputLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderBInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderBInputDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderBInputDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderBInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderBInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderBInputDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderBInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderBInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderBInputDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityEncoderBInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityEncoderBInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityEncoderBInputDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityMeasTime(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityMeasTime(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityMeasTime(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIVelocityDiv(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIVelocityDiv(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCIVelocityDiv(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepFirstTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepFirstTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepFirstTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepFirstTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepFirstTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepFirstTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepFirstLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepFirstLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepFirstLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepFirstDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepFirstDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepFirstDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepFirstDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepFirstDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepFirstDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepFirstDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepFirstDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepFirstDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepFirstDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepFirstDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepFirstDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepFirstDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepFirstDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepFirstDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepFirstEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepFirstEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepFirstEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepSecondTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepSecondTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepSecondTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepSecondTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepSecondTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepSecondTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepSecondLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepSecondLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepSecondLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepSecondDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepSecondDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepSecondDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepSecondDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepSecondDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepSecondDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepSecondDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepSecondDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepSecondDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepSecondDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepSecondDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepSecondDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepSecondDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepSecondDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepSecondDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCITwoEdgeSepSecondEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCITwoEdgeSepSecondEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCITwoEdgeSepSecondEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISemiPeriodStartingEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCISemiPeriodStartingEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCISemiPeriodStartingEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseFreqStartEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseFreqStartEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseFreqStartEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTimeStartEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTimeStartEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTimeStartEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTicksTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTicksTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTicksTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTicksTermCfg(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTicksTermCfg(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTicksTermCfg(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTicksLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTicksLogicLvlBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTicksLogicLvlBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTicksDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTicksDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTicksDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTicksDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTicksDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTicksDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTicksDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTicksDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTicksDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTicksDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTicksDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTicksDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTicksDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTicksDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTicksDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPulseTicksStartEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPulseTicksStartEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPulseTicksStartEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICtrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICtrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICtrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICtrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICtrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICtrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICtrTimebaseActiveEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICtrTimebaseActiveEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCICtrTimebaseActiveEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICtrTimebaseDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICtrTimebaseDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICtrTimebaseDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICtrTimebaseDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICtrTimebaseDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICtrTimebaseDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICtrTimebaseDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCICtrTimebaseDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCICtrTimebaseDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICtrTimebaseDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCICtrTimebaseDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCICtrTimebaseDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICtrTimebaseDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICtrTimebaseDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCICtrTimebaseDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIThreshVoltage(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIThreshVoltage(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIThreshVoltage(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCICount(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetCIOutputState(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetCITCReached(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetCICtrTimebaseMasterTimebaseDiv(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCICtrTimebaseMasterTimebaseDiv(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCICtrTimebaseMasterTimebaseDiv(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISampClkOverrunBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCISampClkOverrunBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCISampClkOverrunBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCISampClkOverrunSentinelVal(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCISampClkOverrunSentinelVal(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCISampClkOverrunSentinelVal(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDataXferMech(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIDataXferMech(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIDataXferMech(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIDataXferReqCond(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIDataXferReqCond(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCIDataXferReqCond(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCIUsbXferReqSize(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCIUsbXferReqCount(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIMemMapEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCINumPossiblyInvalidSamps(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetCIDupCountPrevent(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIDupCountPrevent(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCIDupCountPrevent(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIPrescaler(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCIPrescaler(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCIPrescaler(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCIMaxMeasPeriod(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCIMaxMeasPeriod(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCIMaxMeasPeriod(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOOutputType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetCOPulseIdleState(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseIdleState(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseIdleState(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseTerm(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCOPulseTerm(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseTerm(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseTimeUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseTimeUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseTimeUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseHighTime(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseHighTime(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseHighTime(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseLowTime(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseLowTime(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseLowTime(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseTimeInitialDelay(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseTimeInitialDelay(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseTimeInitialDelay(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseDutyCyc(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseDutyCyc(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseDutyCyc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseFreqUnits(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseFreqUnits(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseFreqUnits(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseFreq(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseFreq(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseFreq(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseFreqInitialDelay(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseFreqInitialDelay(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseFreqInitialDelay(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseHighTicks(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseHighTicks(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseHighTicks(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseLowTicks(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseLowTicks(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseLowTicks(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseTicksInitialDelay(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPulseTicksInitialDelay(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCOPulseTicksInitialDelay(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCtrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCOCtrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCOCtrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCtrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCOCtrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCOCtrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCtrTimebaseActiveEdge(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOCtrTimebaseActiveEdge(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCOCtrTimebaseActiveEdge(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCtrTimebaseDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOCtrTimebaseDigFltrEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCOCtrTimebaseDigFltrEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCtrTimebaseDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCOCtrTimebaseDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCOCtrTimebaseDigFltrMinPulseWidth(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCtrTimebaseDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetCOCtrTimebaseDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetCOCtrTimebaseDigFltrTimebaseSrc(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCtrTimebaseDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetCOCtrTimebaseDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetCOCtrTimebaseDigFltrTimebaseRate(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCtrTimebaseDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOCtrTimebaseDigSyncEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCOCtrTimebaseDigSyncEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCount(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetCOOutputState(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetCOAutoIncrCnt(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOAutoIncrCnt(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCOAutoIncrCnt(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOCtrTimebaseMasterTimebaseDiv(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOCtrTimebaseMasterTimebaseDiv(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCOCtrTimebaseMasterTimebaseDiv(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPulseDone(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetCOEnableInitialDelayOnRetrigger(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOEnableInitialDelayOnRetrigger(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCOEnableInitialDelayOnRetrigger(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOConstrainedGenMode(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOConstrainedGenMode(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCOConstrainedGenMode(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOUseOnlyOnBrdMem(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOUseOnlyOnBrdMem(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCOUseOnlyOnBrdMem(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCODataXferMech(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCODataXferMech(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCODataXferMech(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCODataXferReqCond(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetCODataXferReqCond(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetCODataXferReqCond(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOUsbXferReqSize(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCOUsbXferReqSize(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOUsbXferReqCount(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCOUsbXferReqCount(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOMemMapEnable(TaskHandle taskHandle, const char channel[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetCOMemMapEnable(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCOPrescaler(TaskHandle taskHandle, const char channel[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetCOPrescaler(TaskHandle taskHandle, const char channel[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetCOPrescaler(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetCORdyForNewVal(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetChanType(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxGetPhysicalChanName(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetPhysicalChanName(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxGetChanDescr(TaskHandle taskHandle, const char channel[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetChanDescr(TaskHandle taskHandle, const char channel[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetChanDescr(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetChanIsGlobal(TaskHandle taskHandle, const char channel[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetChanSyncUnlockBehavior(TaskHandle taskHandle, const char channel[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetChanSyncUnlockBehavior(TaskHandle taskHandle, const char channel[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetChanSyncUnlockBehavior(TaskHandle taskHandle, const char channel[]) {return 0;}
int32 __CFUNC DAQmxGetExportedAIConvClkOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedAIConvClkOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedAIConvClkOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAIConvClkPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxGetExported10MHzRefClkOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExported10MHzRefClkOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExported10MHzRefClkOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExported20MHzTimebaseOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExported20MHzTimebaseOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExported20MHzTimebaseOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedSampClkOutputBehavior(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedSampClkOutputBehavior(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedSampClkOutputBehavior(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedSampClkOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedSampClkOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedSampClkOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedSampClkDelayOffset(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedSampClkDelayOffset(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetExportedSampClkDelayOffset(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedSampClkPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedSampClkPulsePolarity(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedSampClkPulsePolarity(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedSampClkTimebaseOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedSampClkTimebaseOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedSampClkTimebaseOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedDividedSampClkTimebaseOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedDividedSampClkTimebaseOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedDividedSampClkTimebaseOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAdvTrigOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedAdvTrigOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedAdvTrigOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAdvTrigPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxGetExportedAdvTrigPulseWidthUnits(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedAdvTrigPulseWidthUnits(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedAdvTrigPulseWidthUnits(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAdvTrigPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedAdvTrigPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetExportedAdvTrigPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedPauseTrigOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedPauseTrigOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedPauseTrigOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedPauseTrigLvlActiveLvl(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedPauseTrigLvlActiveLvl(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedPauseTrigLvlActiveLvl(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedRefTrigOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedRefTrigOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedRefTrigOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedRefTrigPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedRefTrigPulsePolarity(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedRefTrigPulsePolarity(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedStartTrigOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedStartTrigOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedStartTrigOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedStartTrigPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedStartTrigPulsePolarity(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedStartTrigPulsePolarity(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAdvCmpltEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedAdvCmpltEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedAdvCmpltEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAdvCmpltEventDelay(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedAdvCmpltEventDelay(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetExportedAdvCmpltEventDelay(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAdvCmpltEventPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedAdvCmpltEventPulsePolarity(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedAdvCmpltEventPulsePolarity(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAdvCmpltEventPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedAdvCmpltEventPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetExportedAdvCmpltEventPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAIHoldCmpltEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedAIHoldCmpltEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedAIHoldCmpltEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedAIHoldCmpltEventPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedAIHoldCmpltEventPulsePolarity(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedAIHoldCmpltEventPulsePolarity(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedChangeDetectEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedChangeDetectEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedChangeDetectEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedChangeDetectEventPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedChangeDetectEventPulsePolarity(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedChangeDetectEventPulsePolarity(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedCtrOutEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedCtrOutEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedCtrOutEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedCtrOutEventOutputBehavior(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedCtrOutEventOutputBehavior(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedCtrOutEventOutputBehavior(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedCtrOutEventPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedCtrOutEventPulsePolarity(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedCtrOutEventPulsePolarity(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedCtrOutEventToggleIdleState(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedCtrOutEventToggleIdleState(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedCtrOutEventToggleIdleState(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedHshkEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedHshkEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedHshkEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedHshkEventOutputBehavior(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedHshkEventOutputBehavior(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedHshkEventOutputBehavior(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedHshkEventDelay(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedHshkEventDelay(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetExportedHshkEventDelay(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedHshkEventInterlockedAssertedLvl(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedHshkEventInterlockedAssertedLvl(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedHshkEventInterlockedAssertedLvl(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedHshkEventInterlockedAssertOnStart(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedHshkEventInterlockedAssertOnStart(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedHshkEventInterlockedAssertOnStart(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedHshkEventInterlockedDeassertDelay(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedHshkEventInterlockedDeassertDelay(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetExportedHshkEventInterlockedDeassertDelay(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedHshkEventPulsePolarity(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedHshkEventPulsePolarity(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedHshkEventPulsePolarity(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedHshkEventPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedHshkEventPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetExportedHshkEventPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedRdyForXferEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedRdyForXferEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedRdyForXferEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedRdyForXferEventLvlActiveLvl(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedRdyForXferEventLvlActiveLvl(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedRdyForXferEventLvlActiveLvl(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedRdyForXferEventDeassertCond(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedRdyForXferEventDeassertCond(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedRdyForXferEventDeassertCond(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedRdyForXferEventDeassertCondCustomThreshold(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedRdyForXferEventDeassertCondCustomThreshold(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedRdyForXferEventDeassertCondCustomThreshold(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedDataActiveEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedDataActiveEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedDataActiveEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedDataActiveEventLvlActiveLvl(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedDataActiveEventLvlActiveLvl(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedDataActiveEventLvlActiveLvl(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedRdyForStartEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedRdyForStartEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedRdyForStartEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedRdyForStartEventLvlActiveLvl(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetExportedRdyForStartEventLvlActiveLvl(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetExportedRdyForStartEventLvlActiveLvl(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedSyncPulseEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedSyncPulseEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedSyncPulseEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetExportedWatchdogExpiredEventOutputTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetExportedWatchdogExpiredEventOutputTerm(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetExportedWatchdogExpiredEventOutputTerm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetReadRelativeTo(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetReadRelativeTo(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetReadRelativeTo(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetReadOffset(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetReadOffset(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetReadOffset(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetReadChannelsToRead(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetReadChannelsToRead(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetReadChannelsToRead(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetReadReadAllAvailSamp(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetReadReadAllAvailSamp(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetReadReadAllAvailSamp(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetReadAutoStart(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetReadAutoStart(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetReadAutoStart(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetReadOverWrite(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetReadOverWrite(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetReadOverWrite(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetLoggingFilePath(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetLoggingFilePath(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetLoggingFilePath(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetLoggingMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetLoggingMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetLoggingMode(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetLoggingTDMSGroupName(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetLoggingTDMSGroupName(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetLoggingTDMSGroupName(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetLoggingTDMSOperation(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetLoggingTDMSOperation(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetLoggingTDMSOperation(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetLoggingPause(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetLoggingPause(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetLoggingPause(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetLoggingSampsPerFile(TaskHandle taskHandle, uInt64 *data) {return 0;}
int32 __CFUNC DAQmxSetLoggingSampsPerFile(TaskHandle taskHandle, uInt64 data) {return 0;}
int32 __CFUNC DAQmxResetLoggingSampsPerFile(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetLoggingFileWriteSize(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetLoggingFileWriteSize(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetLoggingFileWriteSize(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetLoggingFilePreallocationSize(TaskHandle taskHandle, uInt64 *data) {return 0;}
int32 __CFUNC DAQmxSetLoggingFilePreallocationSize(TaskHandle taskHandle, uInt64 data) {return 0;}
int32 __CFUNC DAQmxResetLoggingFilePreallocationSize(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetReadCurrReadPos(TaskHandle taskHandle, uInt64 *data) {return 0;}
int32 __CFUNC DAQmxGetReadAvailSampPerChan(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadTotalSampPerChanAcquired(TaskHandle taskHandle, uInt64 *data) {return 0;}
int32 __CFUNC DAQmxGetReadCommonModeRangeErrorChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadCommonModeRangeErrorChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadExcitFaultChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadExcitFaultChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadOvercurrentChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadOvercurrentChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadOvertemperatureChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadOvertemperatureChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadOpenChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadOpenChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadOpenChansDetails(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadOpenCurrentLoopChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadOpenCurrentLoopChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadOpenThrmcplChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadOpenThrmcplChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadOverloadedChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadOverloadedChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadInputLimitsFaultChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadInputLimitsFaultChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadPLLUnlockedChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadPLLUnlockedChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadPowerSupplyFaultChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadPowerSupplyFaultChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadSyncUnlockedChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadSyncUnlockedChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadAccessoryInsertionOrRemovalDetected(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadDevsWithInsertedOrRemovedAccessories(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetReadChangeDetectHasOverflowed(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadRawDataWidth(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadNumChans(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadDigitalLinesBytesPerChan(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetReadWaitMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetReadWaitMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetReadWaitMode(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetReadSleepTime(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetReadSleepTime(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetReadSleepTime(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRealTimeConvLateErrorsToWarnings(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetRealTimeConvLateErrorsToWarnings(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetRealTimeConvLateErrorsToWarnings(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRealTimeNumOfWarmupIters(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetRealTimeNumOfWarmupIters(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetRealTimeNumOfWarmupIters(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRealTimeWaitForNextSampClkWaitMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetRealTimeWaitForNextSampClkWaitMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetRealTimeWaitForNextSampClkWaitMode(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRealTimeReportMissedSamp(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetRealTimeReportMissedSamp(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetRealTimeReportMissedSamp(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRealTimeWriteRecoveryMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetRealTimeWriteRecoveryMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetRealTimeWriteRecoveryMode(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSwitchScanBreakMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSwitchScanBreakMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSwitchScanBreakMode(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSwitchScanRepeatMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSwitchScanRepeatMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSwitchScanRepeatMode(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSwitchScanWaitingForAdv(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetTaskName(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetTaskChannels(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetTaskNumChans(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetTaskDevices(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetTaskNumDevices(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetTaskComplete(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetSampQuantSampMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampQuantSampMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSampQuantSampMode(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampQuantSampPerChan(TaskHandle taskHandle, uInt64 *data) {return 0;}
int32 __CFUNC DAQmxSetSampQuantSampPerChan(TaskHandle taskHandle, uInt64 data) {return 0;}
int32 __CFUNC DAQmxResetSampQuantSampPerChan(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampTimingType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampTimingType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSampTimingType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkMaxRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxGetSampClkSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetSampClkSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetSampClkSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkActiveEdge(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkActiveEdge(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkActiveEdge(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkOverrunBehavior(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkOverrunBehavior(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkOverrunBehavior(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkUnderflowBehavior(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkUnderflowBehavior(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkUnderflowBehavior(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkTimebaseDiv(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkTimebaseDiv(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkTimebaseDiv(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetSampClkTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetSampClkTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetSampClkTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkTimebaseActiveEdge(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkTimebaseActiveEdge(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkTimebaseActiveEdge(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkTimebaseMasterTimebaseDiv(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkTimebaseMasterTimebaseDiv(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkTimebaseMasterTimebaseDiv(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkTimebaseTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetSampClkDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetSampClkDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetSampClkDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampClkWriteWfmUseInitialWfmDT(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkWriteWfmUseInitialWfmDT(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkWriteWfmUseInitialWfmDT(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetHshkDelayAfterXfer(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetHshkDelayAfterXfer(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetHshkDelayAfterXfer(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetHshkStartCond(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetHshkStartCond(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetHshkStartCond(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetHshkSampleInputDataWhen(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetHshkSampleInputDataWhen(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetHshkSampleInputDataWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetChangeDetectDIRisingEdgePhysicalChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetChangeDetectDIRisingEdgePhysicalChans(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetChangeDetectDIRisingEdgePhysicalChans(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetChangeDetectDIFallingEdgePhysicalChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetChangeDetectDIFallingEdgePhysicalChans(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetChangeDetectDIFallingEdgePhysicalChans(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetChangeDetectDITristate(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetChangeDetectDITristate(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetChangeDetectDITristate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetOnDemandSimultaneousAOEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetOnDemandSimultaneousAOEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetOnDemandSimultaneousAOEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetImplicitUnderflowBehavior(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetImplicitUnderflowBehavior(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetImplicitUnderflowBehavior(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvRateEx(TaskHandle taskHandle, const char deviceNames[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvRateEx(TaskHandle taskHandle, const char deviceNames[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvRateEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetAIConvMaxRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxGetAIConvMaxRateEx(TaskHandle taskHandle, const char deviceNames[], float64 *data) {return 0;}
int32 __CFUNC DAQmxGetAIConvSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAIConvSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAIConvSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvSrcEx(TaskHandle taskHandle, const char deviceNames[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAIConvSrcEx(TaskHandle taskHandle, const char deviceNames[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetAIConvSrcEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetAIConvActiveEdge(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvActiveEdge(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvActiveEdge(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvActiveEdgeEx(TaskHandle taskHandle, const char deviceNames[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvActiveEdgeEx(TaskHandle taskHandle, const char deviceNames[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvActiveEdgeEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetAIConvTimebaseDiv(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvTimebaseDiv(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvTimebaseDiv(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvTimebaseDivEx(TaskHandle taskHandle, const char deviceNames[], uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvTimebaseDivEx(TaskHandle taskHandle, const char deviceNames[], uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvTimebaseDivEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetAIConvTimebaseSrc(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvTimebaseSrc(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvTimebaseSrcEx(TaskHandle taskHandle, const char deviceNames[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvTimebaseSrcEx(TaskHandle taskHandle, const char deviceNames[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvTimebaseSrcEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetDelayFromSampClkDelayUnits(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDelayFromSampClkDelayUnits(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDelayFromSampClkDelayUnits(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDelayFromSampClkDelayUnitsEx(TaskHandle taskHandle, const char deviceNames[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDelayFromSampClkDelayUnitsEx(TaskHandle taskHandle, const char deviceNames[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetDelayFromSampClkDelayUnitsEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetDelayFromSampClkDelay(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDelayFromSampClkDelay(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetDelayFromSampClkDelay(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDelayFromSampClkDelayEx(TaskHandle taskHandle, const char deviceNames[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDelayFromSampClkDelayEx(TaskHandle taskHandle, const char deviceNames[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetDelayFromSampClkDelayEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigFltrEnableEx(TaskHandle taskHandle, const char deviceNames[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigFltrEnableEx(TaskHandle taskHandle, const char deviceNames[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigFltrEnableEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigFltrMinPulseWidthEx(TaskHandle taskHandle, const char deviceNames[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigFltrMinPulseWidthEx(TaskHandle taskHandle, const char deviceNames[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigFltrMinPulseWidthEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigFltrTimebaseSrcEx(TaskHandle taskHandle, const char deviceNames[], char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigFltrTimebaseSrcEx(TaskHandle taskHandle, const char deviceNames[], const char *data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigFltrTimebaseSrcEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigFltrTimebaseRateEx(TaskHandle taskHandle, const char deviceNames[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigFltrTimebaseRateEx(TaskHandle taskHandle, const char deviceNames[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigFltrTimebaseRateEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAIConvDigSyncEnableEx(TaskHandle taskHandle, const char deviceNames[], bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAIConvDigSyncEnableEx(TaskHandle taskHandle, const char deviceNames[], bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAIConvDigSyncEnableEx(TaskHandle taskHandle, const char deviceNames[]) {return 0;}
int32 __CFUNC DAQmxGetMasterTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetMasterTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetMasterTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetMasterTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetMasterTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetMasterTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefClkRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetRefClkRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetRefClkRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefClkSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetRefClkSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetRefClkSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSyncPulseType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSyncPulseType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSyncPulseType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSyncPulseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetSyncPulseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetSyncPulseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSyncPulseTimeWhen(TaskHandle taskHandle, CVIAbsoluteTime *data) {return 0;}
int32 __CFUNC DAQmxSetSyncPulseTimeWhen(TaskHandle taskHandle, CVIAbsoluteTime data) {return 0;}
int32 __CFUNC DAQmxResetSyncPulseTimeWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSyncPulseTimeTimescale(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSyncPulseTimeTimescale(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSyncPulseTimeTimescale(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSyncPulseSyncTime(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxGetSyncPulseMinDelayToStart(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetSyncPulseMinDelayToStart(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetSyncPulseMinDelayToStart(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSyncPulseResetTime(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxGetSyncPulseResetDelay(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetSyncPulseResetDelay(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetSyncPulseResetDelay(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSyncPulseTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetSyncClkInterval(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetSyncClkInterval(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetSyncClkInterval(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetSampTimingEngine(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampTimingEngine(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetSampTimingEngine(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetFirstSampTimestampEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetFirstSampTimestampEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetFirstSampTimestampEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetFirstSampTimestampTimescale(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetFirstSampTimestampTimescale(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetFirstSampTimestampTimescale(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetFirstSampTimestampVal(TaskHandle taskHandle, CVIAbsoluteTime *data) {return 0;}
int32 __CFUNC DAQmxGetFirstSampClkWhen(TaskHandle taskHandle, CVIAbsoluteTime *data) {return 0;}
int32 __CFUNC DAQmxSetFirstSampClkWhen(TaskHandle taskHandle, CVIAbsoluteTime data) {return 0;}
int32 __CFUNC DAQmxResetFirstSampClkWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetFirstSampClkTimescale(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetFirstSampClkTimescale(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetFirstSampClkTimescale(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeStartTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeStartTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeStartTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeStartTrigEdge(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeStartTrigEdge(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeStartTrigEdge(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeStartTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeStartTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeStartTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeStartTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeStartTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeStartTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeStartTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeStartTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeStartTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigPatternStartTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigPatternStartTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigPatternStartTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigPatternStartTrigPattern(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigPatternStartTrigPattern(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigPatternStartTrigPattern(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigPatternStartTrigWhen(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigPatternStartTrigWhen(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDigPatternStartTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigSlope(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigSlope(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigSlope(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigLvl(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigLvl(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigLvl(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigHyst(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigHyst(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigHyst(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigCoupling(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigCoupling(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigCoupling(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeStartTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeStartTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeStartTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeStartTrigSrcs(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeStartTrigSrcs(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeStartTrigSrcs(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeStartTrigSlopes(TaskHandle taskHandle, int32 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeStartTrigSlopes(TaskHandle taskHandle, int32 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeStartTrigSlopes(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeStartTrigLvls(TaskHandle taskHandle, float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeStartTrigLvls(TaskHandle taskHandle, float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeStartTrigLvls(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeStartTrigHysts(TaskHandle taskHandle, float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeStartTrigHysts(TaskHandle taskHandle, float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeStartTrigHysts(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeStartTrigCouplings(TaskHandle taskHandle, int32 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeStartTrigCouplings(TaskHandle taskHandle, int32 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeStartTrigCouplings(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigWhen(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigWhen(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigTop(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigTop(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigTop(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigBtm(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigBtm(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigBtm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigCoupling(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigCoupling(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigCoupling(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinStartTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinStartTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinStartTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigTrigWhen(TaskHandle taskHandle, CVIAbsoluteTime *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigTrigWhen(TaskHandle taskHandle, CVIAbsoluteTime data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigTimescale(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigTimescale(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigTimescale(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigTimestampEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigTimestampEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigTimestampEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigTimestampTimescale(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigTimestampTimescale(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigTimestampTimescale(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigTimestampVal(TaskHandle taskHandle, CVIAbsoluteTime *data) {return 0;}
int32 __CFUNC DAQmxGetStartTrigDelay(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigDelay(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigDelay(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigDelayUnits(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigDelayUnits(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigDelayUnits(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigRetriggerable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigRetriggerable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigRetriggerable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigTrigWin(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigTrigWin(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigTrigWin(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigRetriggerWin(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigRetriggerWin(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigRetriggerWin(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetStartTrigMaxNumTrigsToDetect(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetStartTrigMaxNumTrigsToDetect(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetStartTrigMaxNumTrigsToDetect(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigPretrigSamples(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigPretrigSamples(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigPretrigSamples(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeRefTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeRefTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeRefTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeRefTrigEdge(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeRefTrigEdge(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeRefTrigEdge(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeRefTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeRefTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeRefTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeRefTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeRefTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeRefTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeRefTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeRefTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeRefTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeRefTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeRefTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeRefTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeRefTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeRefTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeRefTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigPatternRefTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigPatternRefTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigPatternRefTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigPatternRefTrigPattern(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigPatternRefTrigPattern(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigPatternRefTrigPattern(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigPatternRefTrigWhen(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigPatternRefTrigWhen(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDigPatternRefTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigSlope(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigSlope(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigSlope(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigLvl(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigLvl(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigLvl(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigHyst(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigHyst(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigHyst(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigCoupling(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigCoupling(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigCoupling(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgEdgeRefTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgEdgeRefTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgEdgeRefTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeRefTrigSrcs(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeRefTrigSrcs(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeRefTrigSrcs(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeRefTrigSlopes(TaskHandle taskHandle, int32 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeRefTrigSlopes(TaskHandle taskHandle, int32 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeRefTrigSlopes(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeRefTrigLvls(TaskHandle taskHandle, float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeRefTrigLvls(TaskHandle taskHandle, float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeRefTrigLvls(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeRefTrigHysts(TaskHandle taskHandle, float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeRefTrigHysts(TaskHandle taskHandle, float64 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeRefTrigHysts(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgMultiEdgeRefTrigCouplings(TaskHandle taskHandle, int32 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxSetAnlgMultiEdgeRefTrigCouplings(TaskHandle taskHandle, int32 *data, uInt32 arraySizeInElements) {return 0;}
int32 __CFUNC DAQmxResetAnlgMultiEdgeRefTrigCouplings(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigWhen(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigWhen(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigTop(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigTop(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigTop(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigBtm(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigBtm(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigBtm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigCoupling(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigCoupling(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigCoupling(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinRefTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinRefTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinRefTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigAutoTrigEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigAutoTrigEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigAutoTrigEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigAutoTriggered(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetRefTrigTimestampEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigTimestampEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigTimestampEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigTimestampTimescale(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigTimestampTimescale(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigTimestampTimescale(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigTimestampVal(TaskHandle taskHandle, CVIAbsoluteTime *data) {return 0;}
int32 __CFUNC DAQmxGetRefTrigDelay(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigDelay(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigDelay(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigRetriggerable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigRetriggerable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigRetriggerable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigTrigWin(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigTrigWin(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigTrigWin(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigRetriggerWin(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigRetriggerWin(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigRetriggerWin(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetRefTrigMaxNumTrigsToDetect(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxSetRefTrigMaxNumTrigsToDetect(TaskHandle taskHandle, uInt32 data) {return 0;}
int32 __CFUNC DAQmxResetRefTrigMaxNumTrigsToDetect(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAdvTrigType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAdvTrigType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAdvTrigType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeAdvTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeAdvTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeAdvTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeAdvTrigEdge(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeAdvTrigEdge(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeAdvTrigEdge(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeAdvTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeAdvTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeAdvTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetHshkTrigType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetHshkTrigType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetHshkTrigType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetInterlockedHshkTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetInterlockedHshkTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetInterlockedHshkTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetInterlockedHshkTrigAssertedLvl(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetInterlockedHshkTrigAssertedLvl(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetInterlockedHshkTrigAssertedLvl(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetPauseTrigType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetPauseTrigType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetPauseTrigType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetPauseTrigTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigWhen(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigWhen(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigLvl(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigLvl(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigLvl(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigHyst(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigHyst(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigHyst(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigCoupling(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigCoupling(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigCoupling(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgLvlPauseTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgLvlPauseTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgLvlPauseTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigWhen(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigWhen(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigTop(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigTop(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigTop(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigBtm(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigBtm(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigBtm(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigCoupling(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigCoupling(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigCoupling(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetAnlgWinPauseTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetAnlgWinPauseTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetAnlgWinPauseTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigLvlPauseTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigLvlPauseTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigLvlPauseTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigLvlPauseTrigWhen(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigLvlPauseTrigWhen(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDigLvlPauseTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigLvlPauseTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigLvlPauseTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDigLvlPauseTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigLvlPauseTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDigLvlPauseTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetDigLvlPauseTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigLvlPauseTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigLvlPauseTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigLvlPauseTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigLvlPauseTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDigLvlPauseTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetDigLvlPauseTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigLvlPauseTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigLvlPauseTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDigLvlPauseTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigPatternPauseTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigPatternPauseTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigPatternPauseTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigPatternPauseTrigPattern(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigPatternPauseTrigPattern(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigPatternPauseTrigPattern(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigPatternPauseTrigWhen(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigPatternPauseTrigWhen(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDigPatternPauseTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetArmStartTrigType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetArmStartTrigType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetArmStartTrigType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetArmStartTerm(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeArmStartTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeArmStartTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeArmStartTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeArmStartTrigEdge(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeArmStartTrigEdge(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeArmStartTrigEdge(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeArmStartTrigDigFltrEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeArmStartTrigDigFltrEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeArmStartTrigDigFltrEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeArmStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeArmStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeArmStartTrigDigFltrMinPulseWidth(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeArmStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeArmStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeArmStartTrigDigFltrTimebaseSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeArmStartTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeArmStartTrigDigFltrTimebaseRate(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeArmStartTrigDigFltrTimebaseRate(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeArmStartTrigDigSyncEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeArmStartTrigDigSyncEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeArmStartTrigDigSyncEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetArmStartTrigTrigWhen(TaskHandle taskHandle, CVIAbsoluteTime *data) {return 0;}
int32 __CFUNC DAQmxSetArmStartTrigTrigWhen(TaskHandle taskHandle, CVIAbsoluteTime data) {return 0;}
int32 __CFUNC DAQmxResetArmStartTrigTrigWhen(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetArmStartTrigTimescale(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetArmStartTrigTimescale(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetArmStartTrigTimescale(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetArmStartTrigTimestampEnable(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetArmStartTrigTimestampEnable(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetArmStartTrigTimestampEnable(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetArmStartTrigTimestampTimescale(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetArmStartTrigTimestampTimescale(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetArmStartTrigTimestampTimescale(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetArmStartTrigTimestampVal(TaskHandle taskHandle, CVIAbsoluteTime *data) {return 0;}
int32 __CFUNC DAQmxGetTriggerSyncType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetTriggerSyncType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetTriggerSyncType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetWatchdogTimeout(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetWatchdogTimeout(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetWatchdogTimeout(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetWatchdogExpirTrigType(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetWatchdogExpirTrigType(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetWatchdogExpirTrigType(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetWatchdogExpirTrigTrigOnNetworkConnLoss(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxSetWatchdogExpirTrigTrigOnNetworkConnLoss(TaskHandle taskHandle, bool32 data) {return 0;}
int32 __CFUNC DAQmxResetWatchdogExpirTrigTrigOnNetworkConnLoss(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeWatchdogExpirTrigSrc(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeWatchdogExpirTrigSrc(TaskHandle taskHandle, const char *data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeWatchdogExpirTrigSrc(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetDigEdgeWatchdogExpirTrigEdge(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetDigEdgeWatchdogExpirTrigEdge(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetDigEdgeWatchdogExpirTrigEdge(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetWatchdogDOExpirState(TaskHandle taskHandle, const char lines[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetWatchdogDOExpirState(TaskHandle taskHandle, const char lines[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetWatchdogDOExpirState(TaskHandle taskHandle, const char lines[]) {return 0;}
int32 __CFUNC DAQmxGetWatchdogAOOutputType(TaskHandle taskHandle, const char lines[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetWatchdogAOOutputType(TaskHandle taskHandle, const char lines[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetWatchdogAOOutputType(TaskHandle taskHandle, const char lines[]) {return 0;}
int32 __CFUNC DAQmxGetWatchdogAOExpirState(TaskHandle taskHandle, const char lines[], float64 *data) {return 0;}
int32 __CFUNC DAQmxSetWatchdogAOExpirState(TaskHandle taskHandle, const char lines[], float64 data) {return 0;}
int32 __CFUNC DAQmxResetWatchdogAOExpirState(TaskHandle taskHandle, const char lines[]) {return 0;}
int32 __CFUNC DAQmxGetWatchdogCOExpirState(TaskHandle taskHandle, const char lines[], int32 *data) {return 0;}
int32 __CFUNC DAQmxSetWatchdogCOExpirState(TaskHandle taskHandle, const char lines[], int32 data) {return 0;}
int32 __CFUNC DAQmxResetWatchdogCOExpirState(TaskHandle taskHandle, const char lines[]) {return 0;}
int32 __CFUNC DAQmxGetWatchdogHasExpired(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteRelativeTo(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetWriteRelativeTo(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetWriteRelativeTo(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetWriteOffset(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetWriteOffset(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetWriteOffset(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetWriteRegenMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetWriteRegenMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetWriteRegenMode(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetWriteCurrWritePos(TaskHandle taskHandle, uInt64 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteOvercurrentChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteOvercurrentChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetWriteOvertemperatureChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteOvertemperatureChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetWriteExternalOvervoltageChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteExternalOvervoltageChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetWriteOverloadedChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteOverloadedChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetWriteOpenCurrentLoopChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteOpenCurrentLoopChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetWritePowerSupplyFaultChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetWritePowerSupplyFaultChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetWriteSyncUnlockedChansExist(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteSyncUnlockedChans(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetWriteSpaceAvail(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteTotalSampPerChanGenerated(TaskHandle taskHandle, uInt64 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteAccessoryInsertionOrRemovalDetected(TaskHandle taskHandle, bool32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteDevsWithInsertedOrRemovedAccessories(TaskHandle taskHandle, char *data, uInt32 bufferSize) {return 0;}
int32 __CFUNC DAQmxGetWriteRawDataWidth(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteNumChans(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetWriteWaitMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetWriteWaitMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetWriteWaitMode(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetWriteSleepTime(TaskHandle taskHandle, float64 *data) {return 0;}
int32 __CFUNC DAQmxSetWriteSleepTime(TaskHandle taskHandle, float64 data) {return 0;}
int32 __CFUNC DAQmxResetWriteSleepTime(TaskHandle taskHandle) {return 0;}
int32 __CFUNC DAQmxGetWriteDigitalLinesBytesPerChan(TaskHandle taskHandle, uInt32 *data) {return 0;}
int32 __CFUNC DAQmxGetSampClkTimingResponseMode(TaskHandle taskHandle, int32 *data) {return 0;}
int32 __CFUNC DAQmxSetSampClkTimingResponseMode(TaskHandle taskHandle, int32 data) {return 0;}
int32 __CFUNC DAQmxResetSampClkTimingResponseMode(TaskHandle taskHandle) {return 0;}
