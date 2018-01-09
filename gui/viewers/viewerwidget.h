#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "gui/viewers/imageviewer.h"
#include "gui/viewers/videoplayergl.h"

enum CurrentWidget {
    IMAGEVIEWER,
    VIDEOPLAYER,
    UNSET
};

class ViewerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ViewerWidget(QWidget *parent = 0);
    QRectF imageRect();
    float currentScale();
    QSize sourceSize();

    void enableZoomInteraction();
    void disableZoomInteraction();
    bool zoomInteractionEnabled();
private:
    QHBoxLayout layout;
    ImageViewer *imageViewer;
    VideoPlayerGL *videoPlayer;
    void initImageViewer();
    void initVideoPlayer();

    void enableImageViewer();
    void enableVideoPlayer();

    CurrentWidget currentWidget;
    QColor bgColor;
    bool zoomInteraction;

private slots:
    void readSettings();

signals:
    void scalingRequested(QSize);
    void zoomIn();
    void zoomOut();
    void zoomInCursor();
    void zoomOutCursor();
    void scrollUp();
    void scrollDown();
    void fitWindow();
    void fitWidth();
    void fitOriginal();

public slots:
    bool showImage(QPixmap *pixmap);
    bool showAnimation(QMovie *movie);
    bool showVideo(Clip *clip);
    void stopPlayback();
    void setFitMode(ImageFitMode mode);
    ImageFitMode fitMode();
    void onScalingFinished(QPixmap *scaled);
    void closeImage();

protected:
    virtual void paintEvent(QPaintEvent* event);
    void mouseMoveEvent(QMouseEvent *event);

};

#endif // VIEWERWIDGET_H
