#pragma once

#include "platform.hpp"

#include <string>

#define MODE_ID_AUTO -1

class DeckLinkDeviceMode {
protected:
	long long id;
	ComPtr<IDeckLinkDisplayMode> mode;
	std::string name;

public:
	DeckLinkDeviceMode(IDeckLinkDisplayMode *mode, long long id);
	DeckLinkDeviceMode(const std::string &name, long long id);
	virtual ~DeckLinkDeviceMode(void);

	BMDDisplayMode GetDisplayMode(void) const;
	BMDDisplayModeFlags GetDisplayModeFlags(void) const;
	long long GetId(void) const;
	const std::string &GetName(void) const;
	bool IsEqualFrameRate(int64_t num, int64_t den);

	void SetMode(IDeckLinkDisplayMode *mode);

	int GetWidth();
	int GetHeight();
	bool GetFrameRate(BMDTimeValue *frameDuration, BMDTimeScale *timeScale);
};
