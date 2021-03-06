#ifndef PLAYBACK_H_
#define PLAYBACK_H_
#include <sys/types.h>

typedef enum {PLAYBACK_OPEN, PLAYBACK_CLOSE, PLAYBACK_PLAY, PLAYBACK_STOP, PLAYBACK_PAUSE, PLAYBACK_CONTINUE, PLAYBACK_FLUSH, PLAYBACK_TERM, PLAYBACK_FASTFORWARD, PLAYBACK_SEEK, PLAYBACK_SEEK_ABS, PLAYBACK_PTS, PLAYBACK_LENGTH, PLAYBACK_SWITCH_AUDIO, PLAYBACK_SWITCH_SUBTITLE, PLAYBACK_INFO, PLAYBACK_SLOWMOTION, PLAYBACK_FASTBACKWARD, PLAYBACK_GET_FRAME_COUNT, PLAYBACK_SWITCH_TELETEXT, PLAYBACK_SWITCH_DVBSUBTITLE, PLAYBACK_FRAMEBUFFER_LOCK, PLAYBACK_FRAMEBUFFER_UNLOCK} PlaybackCmd_t;

typedef struct PlaybackHandler_s
{
	char *Name;

	int fd;

	unsigned char isFile;
	unsigned char isHttp;

	unsigned char isPlaying;
	unsigned char isPaused;
	unsigned char isForwarding;
	unsigned char isSeeking;
	unsigned char isCreationPhase;

	float BackWard;
	int SlowMotion;
	int Speed;
	int AVSync;

	unsigned char isVideo;
	unsigned char isAudio;
	unsigned char isSubtitle;
	unsigned char isDvbSubtitle;
	unsigned char isTeletext;
	unsigned char mayWriteToFramebuffer;
	unsigned char abortRequested;

	int (* Command)(/*Context_t*/void *, PlaybackCmd_t, void *);
	char *uri;
	off_t size;
	unsigned char noprobe; /* hack: only minimal probing in av_find_stream_info */
} PlaybackHandler_t;

#endif
