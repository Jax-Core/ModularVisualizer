
[AudioAnalyzer]
Measure=Plugin
Plugin=AudioAnalyzer
Type=Parent
Source=[#AnalyzerPort]
ProcessingUnits=Main
Unit-Main=Channels [#Channel] | Handlers MainFFT, Layer1BR(MainFFT), Layer1BCT(Layer1BR), Layer1Output(Layer1BCT), Layer2BR(MainFFT), Layer2BCT(Layer2BR), Layer2Output(Layer2BCT), Layer3BR(MainFFT), Layer3BCT(Layer3BR), Layer3Output(Layer3BCT) | Filter Custom bqHighPass(Q 0.2, Freq 20, ForcedGain 5.58), bqLowPass(Q 1, Freq 16000, ForcedGain 20)
Handler-MainFFT=Type FFT | BinWidth 8 | OverlapBoost 10 | CascadesCount 2 | WindowFunction [#WindowFunction]

Handler-Layer1BR=Type BandResampler | Bands Log(Count 21, FreqMin 20, FreqMax 16000) | CubicInterpolation true
Handler-Layer1BCT=Type BandCascadeTransformer | MixFunction Average | MinWeight 0.01 | TargetWeight 2 | ZeroLevelMultiplier 1
Handler-Layer1Output=Type TimeResampler | Attack [#Attack] | Decay [#Decay] | Transform dB, Map(From -[#MaxSensitivity] : -[#MinSensitivity]), Clamp


Handler-Layer2BR=Type BandResampler | Bands Log(Count 40, FreqMin 20, FreqMax 16000) | CubicInterpolation true
Handler-Layer2BCT=Type BandCascadeTransformer | MixFunction Average | MinWeight 0.01 | TargetWeight 2 | ZeroLevelMultiplier 1
Handler-Layer2Output=Type TimeResampler | Attack [#Attack] | Decay [#Decay] | Transform dB, Map(From -[#MaxSensitivity] : -[#MinSensitivity]), Clamp


Handler-Layer3BR=Type BandResampler | Bands Log(Count 78, FreqMin 20, FreqMax 16000) | CubicInterpolation true
Handler-Layer3BCT=Type BandCascadeTransformer | MixFunction Average | MinWeight 0.01 | TargetWeight 2 | ZeroLevelMultiplier 1
Handler-Layer3Output=Type TimeResampler | Attack [#Attack] | Decay [#Decay] | Transform dB, Map(From -[#MaxSensitivity] : -[#MinSensitivity]), Clamp


LogUnusedOptions=false

