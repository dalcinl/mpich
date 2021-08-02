/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef POSIX_WIN_H_INCLUDED
#define POSIX_WIN_H_INCLUDED

#include "posix_impl.h"

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_start(MPIR_Group * group, int assert,
                                                       MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_start(group, assert, win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_complete(MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_complete(win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_post(MPIR_Group * group, int assert,
                                                      MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_post(group, assert, win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_wait(MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_wait(win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_test(MPIR_Win * win, int *flag)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_test(win, flag);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_lock(int lock_type, int rank, int assert,
                                                      MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_lock(lock_type, rank, assert, win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_unlock(int rank, MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_unlock(rank, win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_fence(int assert, MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_fence(assert, win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_shared_query(MPIR_Win * win,
                                                              int rank,
                                                              MPI_Aint * size, int *disp_unit,
                                                              void *baseptr)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_shared_query(win, rank, size, disp_unit, baseptr);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_flush(int rank, MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_flush(rank, win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_flush_local_all(MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_flush_local_all(win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_unlock_all(MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_unlock_all(win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_flush_local(int rank, MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_flush_local(rank, win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_sync(MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_sync(win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_flush_all(MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_flush_all(win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_mpi_win_lock_all(int assert, MPIR_Win * win)
{
    int mpi_errno;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDIG_mpi_win_lock_all(assert, win);

    MPIR_FUNC_EXIT;

    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_rma_win_cmpl_hook(MPIR_Win * win)
{
    MPIR_FUNC_ENTER;

    /* Always perform barrier to ensure ordering of local load/store. */
    MPL_atomic_read_write_barrier();

    MPIDI_POSIX_win_t *posix_win = &win->dev.shm.posix;
    MPIDI_POSIX_rma_outstanding_req_flushall(posix_win);

    MPIR_FUNC_EXIT;
    return MPI_SUCCESS;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_rma_win_local_cmpl_hook(MPIR_Win * win)
{
    MPIR_FUNC_ENTER;

    /* Always perform barrier to ensure ordering of local load/store. */
    MPL_atomic_read_write_barrier();

    MPIDI_POSIX_win_t *posix_win = &win->dev.shm.posix;
    MPIDI_POSIX_rma_outstanding_req_flushall(posix_win);

    MPIR_FUNC_EXIT;
    return MPI_SUCCESS;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_rma_target_cmpl_hook(int rank ATTRIBUTE((unused)),
                                                              MPIR_Win * win)
{
    MPIR_FUNC_ENTER;

    /* Always perform barrier to ensure ordering of local load/store. */
    MPL_atomic_read_write_barrier();

    MPIDI_POSIX_win_t *posix_win = &win->dev.shm.posix;
    MPIDI_POSIX_rma_outstanding_req_flushall(posix_win);

    MPIR_FUNC_EXIT;
    return MPI_SUCCESS;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_rma_target_local_cmpl_hook(int rank ATTRIBUTE((unused)),
                                                                    MPIR_Win * win)
{
    MPIR_FUNC_ENTER;

    /* Always perform barrier to ensure ordering of local load/store. */
    MPL_atomic_read_write_barrier();

    MPIDI_POSIX_win_t *posix_win = &win->dev.shm.posix;
    MPIDI_POSIX_rma_outstanding_req_flushall(posix_win);

    MPIR_FUNC_EXIT;
    return MPI_SUCCESS;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_rma_op_cs_enter_hook(MPIR_Win * win)
{
    int mpi_errno = MPI_SUCCESS;
    MPIDI_POSIX_win_t *posix_win = NULL;
    MPIR_FUNC_ENTER;

    posix_win = &win->dev.shm.posix;
    MPIDI_POSIX_RMA_MUTEX_LOCK(posix_win->shm_mutex_ptr);

  fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_rma_op_cs_exit_hook(MPIR_Win * win)
{
    int mpi_errno = MPI_SUCCESS;
    MPIDI_POSIX_win_t *posix_win = NULL;
    MPIR_FUNC_ENTER;

    posix_win = &win->dev.shm.posix;
    MPIDI_POSIX_RMA_MUTEX_UNLOCK(posix_win->shm_mutex_ptr);

  fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

/* non-inlined function prototypes */

int MPIDI_POSIX_shm_win_init_hook(MPIR_Win * win);

#endif /* POSIX_WIN_H_INCLUDED */
