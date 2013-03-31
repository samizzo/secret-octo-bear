#ifndef YFROGUPLOADSTATUS_H
#define YFROGUPLOADSTATUS_H

#include <QObject>
#include <QString>
#include <QtXml>

/**
 *   Status of a yfrog image upload.
 */
class YfrogUploadStatus : public QObject
{
	Q_OBJECT

	public:
		enum Status
		{
			Ok,
			AuthFailed,
			MediaNotFound,
			UnsupportedMediaType,
			MediaTooBig,
			UnknownError,
		};

		YfrogUploadStatus(const QDomDocument& xml);

		const QString& getMediaId() const;
		void setMediaId(const QString& mediaId);

		const QString& getMediaUrl() const;
		void setMediaUrl(const QString& mediaUrl);

		Status getStatus() const;
		void setStatus(Status status);

		QString getStatusString() const;

	private:
		QString m_mediaId;
		QString m_mediaUrl;
		Status m_status;
};

inline const QString& YfrogUploadStatus::getMediaId() const
{
	return m_mediaId;
}

inline void YfrogUploadStatus::setMediaId(const QString& mediaId)
{
	m_mediaId = mediaId;
}

inline const QString& YfrogUploadStatus::getMediaUrl() const
{
	return m_mediaUrl;
}

inline void YfrogUploadStatus::setMediaUrl(const QString& mediaUrl)
{
	m_mediaUrl = mediaUrl;
}

inline YfrogUploadStatus::Status YfrogUploadStatus::getStatus() const
{
	return m_status;
}

inline void YfrogUploadStatus::setStatus(Status status)
{
	m_status = status;
}

inline QString YfrogUploadStatus::getStatusString() const
{
	switch (m_status)
	{
		case YfrogUploadStatus::Ok:
		{
			return "Ok";
		}

		case YfrogUploadStatus::AuthFailed:
		{
			return "Authorisation with twitter failed";
		}

		case YfrogUploadStatus::MediaNotFound:
		{
			return "Media not found";
		}

		case YfrogUploadStatus::UnsupportedMediaType:
		{
			return "Unsupported media type";
		}

		case YfrogUploadStatus::MediaTooBig:
		{
			return "Media too big";
		}

		default:
		{
			return "Unknown error";
		}
	}
}

#endif // YFROGUPLOADSTATUS_H