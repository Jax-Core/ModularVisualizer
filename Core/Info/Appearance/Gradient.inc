[Title]
Text=Gradient Customization

[Description]
Text=Customize each layer's linear gradient style using Rainmeter's gradient format. More info and syntax here: https://docs.rainmeter.net/manual/meters/shape/#LinearGradient
MouseOverAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S | Des:Link"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.String:S"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["https://docs.rainmeter.net/manual/meters/shape/#LinearGradient"]
[Des:Link]
InlinePattern=https://.*
InlineSetting=Underline
InlinePattern2=https://.*
InlineSetting2=Color | 31, 69, 174